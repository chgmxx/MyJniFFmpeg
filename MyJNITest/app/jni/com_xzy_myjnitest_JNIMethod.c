//
// Created by xzy on 16-10-20.
//
#include <string.h>
#include <jni.h>
#include <android/log.h>
#include <stdio.h>
#include "libavcodec/avcodec.h"
#include "ffmpeg.h"
#define TAG "xuzhiyong_JNI"

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    __android_log_print(ANDROID_LOG_INFO, TAG,"=====Start to load JNI=======");
    return JNI_VERSION_1_6;
}

jstring Java_com_xzy_myjnitest_JNIMethod_hello(JNIEnv * env, jclass thiz){

   __android_log_print(ANDROID_LOG_INFO, TAG, "begin to vcodec");
           char const *str;
           int argc=9;
           char *argv[9];
   //        argv[0]="ffmpeg";
   //        argv[1]="-i";
   //        argv[2]="/storage/emulated/0/appwonderroot/v/raw/vedio367994338.mp4";
   //        argv[3]="-i";
   //        argv[4]="/storage/emulated/0/appwonderroot/v/raw/vedio367994338.mp4";
   //        argv[5]="-vcodec";
   //        argv[6]="copy";
   //        argv[7]="-acodec";
   //        argv[8] = "copy";
   //        argv[9]="/storage/emulated/0/appwonderroot/v/raw/newoutput.avi";
           argv[0] = "ffmpeg";
           argv[1] = "-y";
           argv[2] = "-i";
           argv[3] = "/storage/emulated/0/appwonderroot/v/raw/vedio-1586478489.mp4";
           argv[4] = "-strict";
           argv[5] = "experimental";
           argv[6] = "-b";
           argv[7] = "500";
           argv[8] = "/storage/emulated/0/appwonderroot/v/cps/c-vedio-1586478489-c.mp4";




           __android_log_print(ANDROID_LOG_INFO, TAG, "finish vcodec...");

       char ver[25];
       sprintf(ver, "%d", avcodec_version());

   //	avcodec_register_all();

   //main(argc, argv);
   //    str="Using FFMPEG doing your job";
   //    return (*env)->NewStringUTF(env,str);
   	//	return (*env)->NewStringUTF(env, "Hello return from jni.");
   		return (*env)->NewStringUTF(env, ver);
}

jint JNICALL Java_com_xzy_myjnitest_JNIMethod_avcoder_1find_1decoder
        (JNIEnv * env, jclass thiz, jint codeId){
    AVCodec *codec = NULL;

    avcodec_register_all();

    codec = avcodec_find_decoder(codeId);



    if(codec != NULL){
        return 0;
    }else{
        return -1;
    }
}

JNIEXPORT jint JNICALL Java_com_xzy_myjnitest_JNIMethod_run
  (JNIEnv *env, jclass obj, jobjectArray commands){
        int argc = (*env)->GetArrayLength(env, commands);
            char *argv[argc];
            int i;
            for (i = 0; i < argc; i++) {
                jstring js = (jstring) (*env)->GetObjectArrayElement(env, commands, i);
                argv[i] = (char*) (*env)->GetStringUTFChars(env, js, 0);
            }

         __android_log_print(ANDROID_LOG_INFO, TAG, "begin to codec s%",commands);
            return run(argc, argv);

}

