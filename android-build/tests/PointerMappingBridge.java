package com.gongmi.callyscaves2;

/** Produces coordinates using the actual Java adapters for Rust integration. */
public final class PointerMappingBridge {
    public static void main(String[] args) {
        java.util.Locale.setDefault(java.util.Locale.ROOT);
        int[][] sizes={{2712,1220},{1952,1220},{2340,1080},{1136,640}};
        for(int[] size:sizes) for(float fraction:new float[]{0.25f,0.5f,0.75f}) {
            int w=size[0], h=size[1];
            float dx=InputViewport.x(w*fraction,w), dy=InputViewport.y(h*fraction,h);
            PointerReleaseQueue q=new PointerReleaseQueue();
            q.down(0); q.release(0,17+w*fraction,31+h*fraction,17,31,w,h);
            PointerReleaseQueue.Release up=q.poll();
            if(up==null) throw new AssertionError("physical release was lost");
            System.out.printf("%f %f %f %f %f%n", fraction,dx,dy,up.x,up.y);
        }
    }
}
