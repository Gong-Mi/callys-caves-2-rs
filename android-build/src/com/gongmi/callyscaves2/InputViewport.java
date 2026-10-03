package com.gongmi.callyscaves2;

/** One canvas mapping for every physical pointer edge and button lookup. */
final class InputViewport {
    static final float WIDTH = 1136.0f;
    static final float HEIGHT = 640.0f;
    static float x(float relativeX, int surfaceWidth) {
        return relativeX * WIDTH / surfaceWidth;
    }
    static float y(float relativeY, int surfaceHeight) {
        return relativeY * HEIGHT / surfaceHeight;
    }
    private InputViewport() {}
}
