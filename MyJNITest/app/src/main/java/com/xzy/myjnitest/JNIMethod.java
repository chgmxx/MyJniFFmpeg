package com.xzy.myjnitest;

/**
 * Created by xzy on 16-10-20.
 */

public class JNIMethod {

    public static native String hello();

    public static native int avcoder_find_decoder(int codecId);

    public native static int run(String[] commands);


    static {
        System.loadLibrary("ffmpeg");
        System.loadLibrary("ffmpeginvoke");
    }
}
