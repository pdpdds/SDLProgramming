LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE    := libgl-wes
LOCAL_SRC_FILES := \
					$(LOCAL_PATH)/context.c \
					$(LOCAL_PATH)/wes.c \
					$(LOCAL_PATH)/wes_begin.c \
					$(LOCAL_PATH)/wes_fragment.c \
					$(LOCAL_PATH)/wes_matrix.c \
					$(LOCAL_PATH)/wes_shader.cp\
					$(LOCAL_PATH)/wes_state.c		

LOCAL_C_INCLUDES := $(LOCAL_PATH)/

#include $(BUILD_STATIC_LIBRARY)


                                                       