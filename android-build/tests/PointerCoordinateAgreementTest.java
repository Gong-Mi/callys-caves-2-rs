package com.gongmi.callyscaves2;

/** Actual pointer-adapter regression: DOWN and UP must share a canvas. */
public final class PointerCoordinateAgreementTest {
    private static void checkClose(float actual, float expected, String what) {
        if (Math.abs(actual - expected) > 0.001f) {
            throw new AssertionError(what + ": actual=" + actual + " expected=" + expected);
        }
    }
    public static void main(String[] args) {
        int[][] sizes = {{2712,1220}, {1136,640}, {2340,1080}, {1952,1220}};
        for (int[] size : sizes) {
            int w=size[0], h=size[1];
            PointerReleaseQueue q=new PointerReleaseQueue();
            q.down(0);
            q.release(0, 17+w/2.0f, 31+h/2.0f, 17, 31, w, h);
            PointerReleaseQueue.Release r=q.poll();
            if(r==null) throw new AssertionError("valid primary release was lost");
            checkClose(InputViewport.x(w/2.0f, w),568.0f,"physical DOWN center X");
            checkClose(InputViewport.y(h/2.0f, h),320.0f,"physical DOWN center Y");
            checkClose(r.x,568.0f,"UP X must match 1136-wide DOWN center");
            checkClose(r.y,320.0f,"UP Y must match 640-high DOWN center");
        }
        System.out.println("physical DOWN/UP canvas agreement passed");
    }
}
