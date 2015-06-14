LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
#CXXFLAGS += -fpermissive
#APP_CPPFLAGS += -fexceptions 

LOCAL_MODULE := main

SDL_PATH := ../../../../../SDL2_Module
DEFALUT_PATH := ../../../../..

LOCAL_SRC_FILES := $(SDL_PATH)/SDL2/src/main/android/SDL_android_main.c \
                   ../../../Class/main.cpp \
				   ../../../Class/wrecks.cpp \
				   ../../../Class/wreck.cpp \
				   ../../../Class/video.cpp \
				   ../../../Class/soundDB.cpp \
				   ../../../Class/sonic.cpp \
				   ../../../Class/smokePuffs.cpp \
				   ../../../Class/smokePuff.cpp \
				   ../../../Class/shots.cpp \
				   ../../../Class/shot.cpp \
				   ../../../Class/shieldGlow.cpp \
				   ../../../Class/settings.cpp \
				   ../../../Class/setDifficulty.cpp \
				   ../../../Class/racers.cpp \
				   ../../../Class/racer.cpp \
				   ../../../Class/options.cpp \
				   ../../../Class/mixer.cpp \
				   ../../../Class/menuArcadeMode.cpp \
				   ../../../Class/surfaceDB.cpp \
				   ../../../Class/items.cpp \
				   ../../../Class/item.cpp \
				   ../../../Class/intro.cpp \
				   ../../../Class/input.cpp \
				   ../../../Class/infoscreen.cpp \
				   ../../../Class/global.cpp \
				   ../../../Class/geometry.cpp \
				   ../../../Class/game.cpp \
				   ../../../Class/formation.cpp \
				   ../../../Class/font.cpp \
				   ../../../Class/explosions.cpp \
				   ../../../Class/explosion.cpp \
				   ../../../Class/enemys.cpp \
				   ../../../Class/enemy.cpp \
				   ../../../Class/boundingBox.cpp \
				   ../../../Class/banners.cpp \
				   ../../../Class/banner.cpp \
				   ../../../Class/background.cpp

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
					
LOCAL_LDLIBS := -ldl -lGLESv1_CM -lGLESv2 -llog -landroid

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

