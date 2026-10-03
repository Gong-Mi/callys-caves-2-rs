package com.gongmi.callyscaves2;

import android.opengl.EGL14;
import android.opengl.EGLConfig;
import android.opengl.EGLContext;
import android.opengl.EGLDisplay;
import android.opengl.EGLSurface;
import android.opengl.GLES30;
import android.util.Log;
import android.view.Surface;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;
import java.nio.IntBuffer;

/**
 * Self-contained GLES3 presenter for the 1136x640 engine framebuffer.
 *
 * The Rust engine hands over one ARGB int[] per frame (little-endian bytes
 * B,G,R,A). We upload it straight into an RGBA texture (the fragment shader
 * swizzles `.bgra`) and draw it as a single quad stretched per axis onto the
 * whole window surface — the same presentation contract as the original
 * runner's window-sized GL backbuffer, with no framework Canvas / HWUI in the
 * path. Sampling is explicitly GL_NEAREST so the pixel-art scale-up stays
 * point-sampled regardless of device defaults.
 *
 * Owns its EGL display/context/surface; all GL calls run on the render thread
 * that calls present(). setSurface() (UI thread) and present() (render thread)
 * are synchronized on this object.
 */
final class GlesPresenter {
    private static final String TAG = "CallysGles";

    private static final int TEX_W = 1136;
    private static final int TEX_H = 640;

    // Triangle strip: top-left, top-right, bottom-left, bottom-right.
    // v=0 is the engine framebuffer's first (top) row, so the quad maps it to
    // the top of the screen without any flip.
    private static final float[] QUAD = {
        -1f,  1f, 0f, 0f,
         1f,  1f, 1f, 0f,
        -1f, -1f, 0f, 1f,
         1f, -1f, 1f, 1f,
    };

    private static final String VERTEX_SHADER =
        "#version 300 es\n" +
        "in vec2 aPos;\n" +
        "in vec2 aUv;\n" +
        "out vec2 vUv;\n" +
        "void main() {\n" +
        "    vUv = aUv;\n" +
        "    gl_Position = vec4(aPos, 0.0, 1.0);\n" +
        "}\n";

    private static final String FRAGMENT_SHADER =
        "#version 300 es\n" +
        "precision mediump float;\n" +
        "uniform sampler2D uTex;\n" +
        "in vec2 vUv;\n" +
        "out vec4 fragColor;\n" +
        "void main() {\n" +
        "    // Engine bytes are little-endian ARGB ints = B,G,R,A in memory;\n" +
        "    // an RGBA upload therefore reads back swapped, so swizzle here.\n" +
        "    fragColor = texture(uTex, vUv).bgra;\n" +
        "}\n";

    private EGLDisplay eglDisplay = EGL14.EGL_NO_DISPLAY;
    private EGLContext eglContext = EGL14.EGL_NO_CONTEXT;
    private EGLSurface eglWindowSurface = EGL14.EGL_NO_SURFACE;
    private EGLConfig eglConfig;

    private int program;
    private int texId;
    private int vbo;
    private int vao;
    private int aPosLoc = -1;
    private int aUvLoc = -1;
    private int uTexLoc = -1;

    private IntBuffer pixelInts;
    private int[] wrappedArray;
    private boolean textureAllocated;

    private Surface pendingSurface;
    private int surfaceWidth;
    private int surfaceHeight;
    private boolean initFailedLogged;
    private boolean blitMissLogged;

    /** Attach (null) or re-attach a window surface. Called on the UI thread. */
    synchronized void setSurface(Surface surface) {
        Log.i(TAG, "setSurface valid=" + (surface != null && surface.isValid())
                + " same=" + (surface == pendingSurface));
        if (surface == pendingSurface) {
            return;
        }
        pendingSurface = surface;
        destroyWindowSurface();
    }

    /** Called from the render thread; true when a frame was swapped. */
    synchronized boolean present(int[] pixels) {
        Surface surface = pendingSurface;
        if (surface == null || !surface.isValid()) {
            if (!blitMissLogged) {
                Log.w(TAG, "present skip: surface " + (surface == null ? "null" : "invalid"));
                blitMissLogged = true;
            }
            return false;
        }
        if (eglDisplay == EGL14.EGL_NO_DISPLAY) {
            if (!initEgl(surface)) {
                return false;
            }
        }
        if (eglWindowSurface == EGL14.EGL_NO_SURFACE) {
            if (!createWindowSurface(surface)) {
                return false;
            }
        }
        if (program == 0 && !createProgram()) {
            return false;
        }
        if (!ensureTexture()) {
            return false;
        }
        if (surfaceWidth <= 0 || surfaceHeight <= 0) {
            return false;
        }

        if (wrappedArray != pixels) {
            wrappedArray = pixels;
            pixelInts = IntBuffer.wrap(pixels);
        } else {
            pixelInts.position(0);
        }

        GLES30.glViewport(0, 0, surfaceWidth, surfaceHeight);
        GLES30.glClearColor(0f, 0f, 0f, 1f);
        GLES30.glClear(GLES30.GL_COLOR_BUFFER_BIT);

        GLES30.glUseProgram(program);
        GLES30.glActiveTexture(GLES30.GL_TEXTURE0);
        GLES30.glBindTexture(GLES30.GL_TEXTURE_2D, texId);
        GLES30.glTexSubImage2D(GLES30.GL_TEXTURE_2D, 0, 0, 0, TEX_W, TEX_H,
                GLES30.GL_RGBA, GLES30.GL_UNSIGNED_BYTE, pixelInts);
        GLES30.glUniform1i(uTexLoc, 0);

        GLES30.glBindVertexArray(vao);
        GLES30.glDrawArrays(GLES30.GL_TRIANGLE_STRIP, 0, 4);
        GLES30.glBindVertexArray(0);

        if (!EGL14.eglSwapBuffers(eglDisplay, eglWindowSurface)) {
            // Surface went away or resized out from under us; drop it and let
            // the next frame (or setSurface) rebuild.
            destroyWindowSurface();
            return false;
        }
        return true;
    }

    synchronized void release() {
        pendingSurface = null;
        destroyWindowSurface();
        if (eglDisplay != EGL14.EGL_NO_DISPLAY) {
            EGL14.eglMakeCurrent(eglDisplay, EGL14.EGL_NO_SURFACE, EGL14.EGL_NO_SURFACE,
                    EGL14.EGL_NO_CONTEXT);
            if (eglContext != EGL14.EGL_NO_CONTEXT) {
                EGL14.eglDestroyContext(eglDisplay, eglContext);
            }
            EGL14.eglTerminate(eglDisplay);
        }
        eglDisplay = EGL14.EGL_NO_DISPLAY;
        eglContext = EGL14.EGL_NO_CONTEXT;
        eglConfig = null;
    }

    private boolean initEgl(Surface surface) {
        eglDisplay = EGL14.eglGetDisplay(EGL14.EGL_DEFAULT_DISPLAY);
        if (eglDisplay == EGL14.EGL_NO_DISPLAY) {
            return fail("eglGetDisplay failed");
        }
        int[] version = new int[2];
        if (!EGL14.eglInitialize(eglDisplay, version, 0, version, 1)) {
            return fail("eglInitialize failed");
        }
        EGLConfig[] configs = new EGLConfig[1];
        int[] numConfigs = new int[1];
        int[] attribs = {
            // 0x40 = EGL_OPENGL_ES3_BIT_KHR (EGL_KHR_create_context); the
            // Android EGL14 wrapper does not expose the constant.
            EGL14.EGL_RENDERABLE_TYPE, 0x00000040,
            EGL14.EGL_RED_SIZE, 8,
            EGL14.EGL_GREEN_SIZE, 8,
            EGL14.EGL_BLUE_SIZE, 8,
            EGL14.EGL_ALPHA_SIZE, 8,
            EGL14.EGL_SURFACE_TYPE, EGL14.EGL_WINDOW_BIT,
            EGL14.EGL_NONE,
        };
        if (!EGL14.eglChooseConfig(eglDisplay, attribs, 0, configs, 0, 1, numConfigs, 0)
                || numConfigs[0] == 0) {
            return fail("no ES3 window config");
        }
        eglConfig = configs[0];
        int[] contextAttribs = {
            EGL14.EGL_CONTEXT_CLIENT_VERSION, 3,
            EGL14.EGL_NONE,
        };
        eglContext = EGL14.eglCreateContext(eglDisplay, eglConfig, EGL14.EGL_NO_CONTEXT,
                contextAttribs, 0);
        if (eglContext == EGL14.EGL_NO_CONTEXT) {
            return fail("eglCreateContext(ES3) failed");
        }
        if (!createWindowSurface(surface)) {
            return false;
        }
        Log.i(TAG, "GLES3 presenter up: EGL " + version[0] + "." + version[1]
                + ", GL_VERSION=" + GLES30.glGetString(GLES30.GL_VERSION));
        return true;
    }

    private boolean createWindowSurface(Surface surface) {
        int[] attribs = { EGL14.EGL_NONE };
        eglWindowSurface = EGL14.eglCreateWindowSurface(eglDisplay, eglConfig, surface,
                attribs, 0);
        if (eglWindowSurface == EGL14.EGL_NO_SURFACE) {
            return fail("eglCreateWindowSurface failed");
        }
        if (!EGL14.eglMakeCurrent(eglDisplay, eglWindowSurface, eglWindowSurface, eglContext)) {
            EGL14.eglDestroySurface(eglDisplay, eglWindowSurface);
            eglWindowSurface = EGL14.EGL_NO_SURFACE;
            return fail("eglMakeCurrent failed");
        }
        // Query the window size once per surface (MIUI wraps eglQuerySurface
        // in a system-resource lookup; doing it per frame spams the log at
        // frame rate and costs a binder round trip).
        int[] dim = new int[1];
        EGL14.eglQuerySurface(eglDisplay, eglWindowSurface, EGL14.EGL_WIDTH, dim, 0);
        surfaceWidth = dim[0];
        EGL14.eglQuerySurface(eglDisplay, eglWindowSurface, EGL14.EGL_HEIGHT, dim, 0);
        surfaceHeight = dim[0];
        return true;
    }

    private void destroyWindowSurface() {
        if (eglDisplay != EGL14.EGL_NO_DISPLAY
                && eglWindowSurface != EGL14.EGL_NO_SURFACE) {
            EGL14.eglMakeCurrent(eglDisplay, EGL14.EGL_NO_SURFACE, EGL14.EGL_NO_SURFACE,
                    EGL14.EGL_NO_CONTEXT);
            EGL14.eglDestroySurface(eglDisplay, eglWindowSurface);
        }
        eglWindowSurface = EGL14.EGL_NO_SURFACE;
    }

    private boolean createProgram() {
        int vs = compileShader(GLES30.GL_VERTEX_SHADER, VERTEX_SHADER);
        int fs = compileShader(GLES30.GL_FRAGMENT_SHADER, FRAGMENT_SHADER);
        if (vs == 0 || fs == 0) {
            return false;
        }
        int prog = GLES30.glCreateProgram();
        GLES30.glAttachShader(prog, vs);
        GLES30.glAttachShader(prog, fs);
        GLES30.glLinkProgram(prog);
        int[] status = new int[1];
        GLES30.glGetProgramiv(prog, GLES30.GL_LINK_STATUS, status, 0);
        GLES30.glDeleteShader(vs);
        GLES30.glDeleteShader(fs);
        if (status[0] == 0) {
            Log.e(TAG, "program link failed: " + GLES30.glGetProgramInfoLog(prog));
            GLES30.glDeleteProgram(prog);
            return false;
        }
        program = prog;
        aPosLoc = GLES30.glGetAttribLocation(program, "aPos");
        aUvLoc = GLES30.glGetAttribLocation(program, "aUv");
        uTexLoc = GLES30.glGetUniformLocation(program, "uTex");

        FloatBuffer quad = ByteBuffer.allocateDirect(QUAD.length * 4)
                .order(ByteOrder.nativeOrder()).asFloatBuffer();
        quad.put(QUAD).position(0);
        int[] bufs = new int[1];
        GLES30.glGenBuffers(1, bufs, 0);
        vbo = bufs[0];
        GLES30.glGenVertexArrays(1, bufs, 0);
        vao = bufs[0];
        GLES30.glBindVertexArray(vao);
        GLES30.glBindBuffer(GLES30.GL_ARRAY_BUFFER, vbo);
        GLES30.glBufferData(GLES30.GL_ARRAY_BUFFER, QUAD.length * 4, quad,
                GLES30.GL_STATIC_DRAW);
        GLES30.glEnableVertexAttribArray(aPosLoc);
        GLES30.glVertexAttribPointer(aPosLoc, 2, GLES30.GL_FLOAT, false, 16, 0);
        GLES30.glEnableVertexAttribArray(aUvLoc);
        GLES30.glVertexAttribPointer(aUvLoc, 2, GLES30.GL_FLOAT, false, 16, 8);
        GLES30.glBindVertexArray(0);
        return true;
    }

    private int compileShader(int type, String source) {
        int shader = GLES30.glCreateShader(type);
        GLES30.glShaderSource(shader, source);
        GLES30.glCompileShader(shader);
        int[] status = new int[1];
        GLES30.glGetShaderiv(shader, GLES30.GL_COMPILE_STATUS, status, 0);
        if (status[0] == 0) {
            Log.e(TAG, "shader compile failed: " + GLES30.glGetShaderInfoLog(shader));
            GLES30.glDeleteShader(shader);
            return 0;
        }
        return shader;
    }

    private boolean ensureTexture() {
        if (textureAllocated) {
            return true;
        }
        int[] tex = new int[1];
        GLES30.glGenTextures(1, tex, 0);
        texId = tex[0];
        GLES30.glBindTexture(GLES30.GL_TEXTURE_2D, texId);
        GLES30.glTexParameteri(GLES30.GL_TEXTURE_2D, GLES30.GL_TEXTURE_MIN_FILTER,
                GLES30.GL_NEAREST);
        GLES30.glTexParameteri(GLES30.GL_TEXTURE_2D, GLES30.GL_TEXTURE_MAG_FILTER,
                GLES30.GL_NEAREST);
        GLES30.glTexParameteri(GLES30.GL_TEXTURE_2D, GLES30.GL_TEXTURE_WRAP_S,
                GLES30.GL_CLAMP_TO_EDGE);
        GLES30.glTexParameteri(GLES30.GL_TEXTURE_2D, GLES30.GL_TEXTURE_WRAP_T,
                GLES30.GL_CLAMP_TO_EDGE);
        GLES30.glTexImage2D(GLES30.GL_TEXTURE_2D, 0, GLES30.GL_RGBA, TEX_W, TEX_H, 0,
                GLES30.GL_RGBA, GLES30.GL_UNSIGNED_BYTE, null);
        textureAllocated = true;
        return true;
    }

    private boolean fail(String message) {
        if (!initFailedLogged) {
            Log.e(TAG, message + " (EGL error 0x" + Integer.toHexString(EGL14.eglGetError()) + ")");
            initFailedLogged = true;
        }
        return false;
    }
}
