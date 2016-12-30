MY_LOCAL_PATH := $(call my-dir)
include /home/ubt/Code/breakpad/src/android/google_breakpad/Android.mk

LOCAL_PATH :=$(MY_LOCAL_PATH)

include $(CLEAR_VARS)

LOCAL_MODULE    := native-lib
LOCAL_SRC_FILES := native-lib.cpp
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog -lz

include $(BUILD_SHARED_LIBRARY)


include $(CLEAR_VARS)

LOCAL_MODULE    := native-crash
LOCAL_SRC_FILES := native_crash.cpp
LOCAL_LDLIBS := -L$(SYSROOT)/usr/lib -llog -lz
LOCAL_STATIC_LIBRARIES += breakpad_client

include $(BUILD_SHARED_LIBRARY)
