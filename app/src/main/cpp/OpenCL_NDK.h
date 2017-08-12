#ifndef OPENCL_NDK_OPENCL_NDK_H
#define OPENCL_NDK_OPENCL_NDK_H

#include <android/log.h>
#include <jni.h>

#define CL_USE_DEPRECATED_OPENCL_1_2_APIS
#include <CL/opencl.h>

#include <cstdlib>
#include <vector>
#include <string>

// used to get logcat outputs which can be regex filtered by the LOG_TAG we give
// So in Logcat you can filter this example by putting Tutorial_TAG
#define LOG_TAG "OpenCL_NDK"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#define __CL_ENABLE_EXCEPTIONS

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

    void OnPause();

    // Cache the Java VM used from the Java layer.
  void SetJavaVM(JavaVM* java_vm) { java_vm_ = java_vm; }

  double runOpenCL();

private:

 // Cached Java VM, caller activity object
  JavaVM* java_vm_;
  jobject calling_activity_obj_;
  jmethodID on_demand_method_;

  // Compute c = a + b.
  const char *kernel_source =
      "#pragma OPENCL EXTENSION cl_khr_fp64 : enable\n"
          "__kernel void vecAdd(  __global double *a,\n"
          "                       __global double *b,\n"
          "                       __global double *c,\n"
          "                       const unsigned int n)\n"
          "{\n"
          "    int id = get_global_id(0);\n"
          "    if (id < n) {\n"
          "        c[id] = a[id] + b[id];\n"
          "    }\n"
          "}\n";
};

#endif //OPENCL_NDK_OPENCL_NDK_H
