LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := gallery
LOCAL_SRC_FILES := util/shader.c gallery.c
LOCAL_LDLIBS 	:= -lGLESv2

include $(BUILD_SHARED_LIBRARY)
