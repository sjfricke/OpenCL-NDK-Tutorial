LOCAL_PATH := $(call my-dir)
PROJECT_ROOT:= $(call my-dir)/../../../../..
APP_ROOT:= $(call my-dir)/../../../..

include $(CLEAR_VARS)
LOCAL_MODULE    := libopencl_ndk
LOCAL_CFLAGS    := -Werror -std=c++11  -I$(LOCAL_PATH)/include/
LOCAL_CFLAGS += -DANDROID_CL
LOCAL_SRC_FILES := native-lib.cpp \
                   OpenCL_NDK.cpp
LOCAL_CFLAGS  += -I$(LOCAL_PATH)/../CL
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../
LOCAL_LDLIBS    := -llog -L$(SYSROOT)/usr/lib -lOpenCL
include $(BUILD_SHARED_LIBRARY)


