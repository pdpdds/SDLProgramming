LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
#CXXFLAGS += -fpermissive
#APP_CPPFLAGS += -fexceptions 

LOCAL_MODULE := main

SDL_PATH := ../../../../../SDL2_Module
DEFALUT_PATH := ../../../../..

LOCAL_SRC_FILES := $(SDL_PATH)/SDL2/src/main/android/SDL_android_main.c \
                   ../../../Class/main.cpp

LCOAL_C_INCLUDES := $(LOCAL_PATH)
LOCAL_C_INCLUDES += $(SDL_PATH)/SDL2/include
LOCAL_C_INCLUDES += ../../../Class
		
LOCAL_SHARED_LIBRARIES := SDL2
					
LOCAL_LDLIBS := -ldl -lGLESv1_CM -lGLESv2 -llog -landroid

include $(BUILD_SHARED_LIBRARY)

$(call import-add-path, $(LOCAL_PATH)/$(SDL_PATH))
$(call import-add-path, $(LOCAL_PATH)/$(DEFALUT_PATH))
$(call import-module, SDL2)
#$(call import-module, external/sockets)


