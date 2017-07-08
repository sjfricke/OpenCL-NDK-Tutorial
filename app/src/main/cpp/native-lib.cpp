#include <jni.h>
#include <string>

#include "OpenCL_NDK.h"

static OpenCL_NDK app;

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jstring JNICALL
Java_spencerfricke_com_opencl_1ndk_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    runOpenCL();
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT void JNICALL
Java_spencerfricke_com_opencl_1ndk_MainActivity_onCreateNDK(
        JNIEnv* env, jobject, jobject caller_activity) {
    app.OnCreate(env, caller_activity);
}

JNIEXPORT void JNICALL
Java_spencerfricke_com_opencl_1ndk_MainActivity_onResumeNDK(
        JNIEnv*, jobject) {
    app.OnResume();
}

JNIEXPORT void JNICALL
Java_spencerfricke_com_opencl_1ndk_MainActivity_onPauseNDK(
        JNIEnv*, jobject) {
    app.OnPause();
}


#ifdef __cplusplus
}
#endif
