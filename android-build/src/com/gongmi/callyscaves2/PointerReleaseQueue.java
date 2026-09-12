package com.gongmi.callyscaves2;

import java.util.concurrent.ConcurrentLinkedQueue;

/** Physical primary-pointer releases, independent of virtual button state. */
final class PointerReleaseQueue {
    static final class Release {
        final float x, y;
        Release(float x, float y) { this.x = x; this.y = y; }
    }
    private final ConcurrentLinkedQueue<Release> events = new ConcurrentLinkedQueue<>();
    private int primary = -1; // UI thread only

    void down(int pointerId) { primary = pointerId; }
    void cancel() { primary = -1; }
    void reset() { cancel(); events.clear(); }

    void release(int pointerId, float x, float y, int left, int top, int width, int height) {
        if (pointerId != primary || primary < 0) return;
        primary = -1;
        x -= left;
        y -= top;
        if (width <= 0 || height <= 0 || !Float.isFinite(x) || !Float.isFinite(y)
                || x < 0 || y < 0 || x >= width || y >= height) return;
        events.add(new Release(x * 960.0f / width, y * 540.0f / height));
    }

    Release poll() { return events.poll(); }
}
