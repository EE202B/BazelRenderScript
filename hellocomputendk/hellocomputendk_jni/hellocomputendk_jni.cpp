#include <jni.h>
#include <android/log.h>
#include <android/bitmap.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "hellocomputendk/jni/rs_mono_wrapper.h"

#define  LOG_TAG    "hellocomputendk_jni"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

extern "C" JNIEXPORT void JNICALL
Java_com_yingnanwang_cmakerstest4_TFRSInterface_nativeMono(JNIEnv * env,
                                                                       jclass,
                                                                       jstring pathObj,
                                                                       jint X,
                                                                       jint Y,
                                                                       jobject jbitmapIn,
                                                                       jobject jbitmapOut
                                                                       )
{
    void* inputPtr = nullptr;
    void* outputPtr = nullptr;
    AndroidBitmap_lockPixels(env, jbitmapIn, &inputPtr);
    AndroidBitmap_lockPixels(env, jbitmapOut, &outputPtr);
    const char * path = env->GetStringUTFChars(pathObj, nullptr);

    // rs compute
    compute(path, X, Y, inputPtr, outputPtr);

    //release the resource
    AndroidBitmap_unlockPixels(env, jbitmapIn);
    AndroidBitmap_unlockPixels(env, jbitmapOut);
    env->ReleaseStringUTFChars(pathObj, path);
}