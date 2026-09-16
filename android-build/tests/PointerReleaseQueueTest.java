package com.gongmi.callyscaves2;

public final class PointerReleaseQueueTest {
    private static void check(boolean condition) {
        if (!condition) throw new AssertionError("pointer release contract");
    }
    public static void main(String[] args) {
        PointerReleaseQueue q = new PointerReleaseQueue();
        q.down(3);
        q.release(8, 580, 320, 100, 50, 960, 540); // secondary finger: not mouse
        check(q.poll() == null);
        q.release(3, 580, 320, 100, 50, 960, 540);
        PointerReleaseQueue.Release r = q.poll();
        check(r != null && r.x == 480 && r.y == 270 && q.poll() == null);
        q.release(3, 580, 320, 100, 50, 960, 540); // duplicate up
        check(q.poll() == null);
        q.down(0);
        q.cancel();
        q.release(0, 10, 10, 0, 0, 960, 540);
        check(q.poll() == null);
        q.down(0);
        q.release(0, 580, 320, 100, 50, 1920, 1080);
        r = q.poll();
        check(r != null && r.x == 240 && r.y == 135);
        for (float x : new float[] {-1, 960, Float.NaN, Float.POSITIVE_INFINITY}) {
            q.down(0);
            q.release(0, x, 10, 0, 0, 960, 540);
            check(q.poll() == null);
        }
        q.down(0);
        q.release(0, 10, 10, 0, 0, 0, 540);
        check(q.poll() == null);
        q.down(0);
        q.release(0, 10, 10, 0, 0, 960, 540);
        q.reset();
        check(q.poll() == null);
        System.out.println("PointerReleaseQueue contract passed");
    }
}
