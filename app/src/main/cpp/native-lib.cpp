#include <jni.h>
#include <string>

#include "OpenCL_NDK.h"

static OpenCL_NDK app;

#ifdef __cplusplus
extern "C" {
#endif

jint JNI_OnLoad(JavaVM* vm, void*) {
    // We need to store a reference to the Java VM so that we can call back
    app.SetJavaVM(vm);
    return JNI_VERSION_1_6;
}

JNIEXPORT jstring JNICALL
Java_spencerfricke_com_opencl_1ndk_MainActivity_stringFromJNI(JNIEnv *env, jobject) {
    double result = app.runOpenCL();
    char return_string[100];
    snprintf(return_string, sizeof(return_string), "Time: %f seconds", result);
    return env->NewStringUTF(return_string);
}

JNIEXPORT void JNICALL
Java_spencerfricke_com_opencl_1ndk_MainActivity_onCreateNDK(
        JNIEnv* env, jobject, jobject caller_activity) {
    app.OnCreate(env, caller_activity);
}

JNIEXPORT void JNICALL
Java_spencerfricke_com_opencl_1ndk_MainActivity_onResumeNDK(JNIEnv*, jobject) {
    app.OnResume();
}

JNIEXPORT void JNICALL
Java_spencerfricke_com_opencl_1ndk_MainActivity_onPauseNDK( JNIEnv*, jobject) {
    app.OnPause();
}


#ifdef __cplusplus
}
#endif
