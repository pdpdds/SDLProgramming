LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
#CXXFLAGS += -fpermissive
#APP_CPPFLAGS += -fexceptions 
LOCAL_CPPFLAGS  := -std=c++11 -frtti

LOCAL_MODULE := main

SDL_PATH := ../../../../../SDL2_Module
DEFALUT_PATH := ../../../../..
FILE_LIST := $(wildcard $(LOCAL_PATH)/../../../Class/*.cpp)

LOCAL_SRC_FILES := $(SDL_PATH)/SDL2/src/main/android/SDL_android_main.c
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)

LCOAL_C_INCLUDES := $(LOCAL_PATH)
LOCAL_C_INCLUDES += $(SDL_PATH)/SDL2_ttf
LOCAL_C_INCLUDES += $(SDL_PATH)/SDL2_image
LOCAL_C_INCLUDES += $(SDL_PATH)/SDL2_mixer
LOCAL_C_INCLUDES += $(SDL_PATH)/SDL2/include
LOCAL_C_INCLUDES += ../../../Class
LOCAL_C_INCLUDES += $(DEFALUT_PATH)/external/sockets
LOCAL_C_INCLUDES += $(DEFALUT_PATH)/external/guichan/include
LOCAL_C_INCLUDES += $(DEFALUT_PATH)/external/iconv/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../external/iconv/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../external
#LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../external/guichan/include
#LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../external/guichan/include/guichan
		
LOCAL_SHARED_LIBRARIES := SDL2 SDL2_ttf SDL2_image SDL2_mixer SDL2_net GUIChan IMSLibrary sockets iconv
					
LOCAL_LDLIBS := -ldl -lGLESv1_CM -lGLESv2 -llog -landroid -lz

include $(BUILD_SHARED_LIBRARY)

$(call import-add-path, $(LOCAL_PATH)/$(SDL_PATH))
$(call import-add-path, $(LOCAL_PATH)/$(DEFALUT_PATH))
$(call import-module, SDL2)
$(call import-module, SDL2_mixer)
$(call import-module, SDL2_mixer/external/libmikmod-3.1.12)
$(call import-module, SDL2_mixer/external/smpeg2-2.0.0)
$(call import-module, SDL2_image)
$(call import-module, SDL2_image/external/libwebp-0.3.0)
$(call import-module, SDL2_image/external/libpng-1.6.2)
$(call import-module, SDL2_ttf)
$(call import-module, SDL2_net)
#$(call import-module, SDL2_gfx)
#$(call import-module, external/sockets)
$(call import-module, external/guichan)
$(call import-module, external/IMSLibrary)
$(call import-module, external/iconv)
