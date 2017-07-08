#ifndef OPENCL_NDK_OPENCL_NDK_H
#define OPENCL_NDK_OPENCL_NDK_H

#include <android/log.h>
#include <jni.h>

#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#include <CL/cl.h>

#include <cstdlib>
#include <vector>
#include <string>

// used to get logcat outputs which can be regex filtered by the LOG_TAG we give
// So in Logcat you can filter this example by putting Tutorial_TAG
#define LOG_TAG "OpenCL_NDK"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#define __CL_ENABLE_EXCEPTIONS

void runOpenCL();

// Class to hold an instance
class OpenCL_NDK {
public:
    OpenCL_NDK() {}

    OpenCL_NDK(const OpenCL_NDK& other) = delete;

    OpenCL_NDK& operator=(const OpenCL_NDK& other) = delete;

    ~OpenCL_NDK() {}

    // @param env, java environment parameter CheckVersion is being called.
    // @param caller_activity, caller of this function.
    void OnCreate(JNIEnv* env, jobject caller_activity);

    void OnResume();

    // Disconnect and stop service.
    void OnPause();


private:

};

#endif //OPENCL_NDK_OPENCL_NDK_H
