LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
#CXXFLAGS += -fpermissive
#APP_CPPFLAGS += -fexceptions 

LOCAL_MODULE := main

SDL_PATH := ../../../../../SDL2_Module
DEFALUT_PATH := ../../../../..

LOCAL_SRC_FILES := $(SDL_PATH)/SDL2/src/main/android/SDL_android_main.c \
                   ../../../Class/animlib.cpp \
				   ../../../Class/arg_parse.cpp \
				   ../../../Class/backgrnd.cpp \
				   ../../../Class/cJSON.cpp \
				   ../../../Class/config.cpp \
				   ../../../Class/destruct.cpp \
				   ../../../Class/editship.cpp \
				   ../../../Class/episodes.cpp \
				   ../../../Class/file.cpp \
				   ../../../Class/fm_synth.cpp \
				   ../../../Class/fmopl.cpp \
				   ../../../Class/font.cpp \
				   ../../../Class/fonthand.cpp \
				   ../../../Class/game_menu.cpp \
				   ../../../Class/helptext.cpp \
				   ../../../Class/joystick.cpp \
				   ../../../Class/jukebox.cpp \
				   ../../../Class/keyboard.cpp \
				   ../../../Class/lds_play.cpp \
				   ../../../Class/loudness.cpp \
				   ../../../Class/lvllib.cpp \
				   ../../../Class/lvlmast.cpp \
				   ../../../Class/mainint.cpp \
				   ../../../Class/menus.cpp \
				   ../../../Class/mingw_fixes.cpp \
				   ../../../Class/mouse.cpp \
				   ../../../Class/mtrand.cpp \
				   ../../../Class/musmast.cpp \
				   ../../../Class/network.cpp \
				   ../../../Class/nortsong.cpp \
				   ../../../Class/nortvars.cpp \
				   ../../../Class/opentyr.cpp \
				   ../../../Class/palette.cpp \
				   ../../../Class/params.cpp \
				   ../../../Class/pcxload.cpp \
				   ../../../Class/pcxmast.cpp \
				   ../../../Class/picload.cpp \
				   ../../../Class/player.cpp \
				   ../../../Class/scroller.cpp \
				   ../../../Class/SDLSingleton.cpp \
				   ../../../Class/setup.cpp \
				   ../../../Class/sizebuf.cpp \
				   ../../../Class/sndmast.cpp \
				   ../../../Class/sprite.cpp \
				   ../../../Class/starlib.cpp \
				   ../../../Class/tyrian2.cpp \
				   ../../../Class/varz.cpp \
				   ../../../Class/vga_palette.cpp \
				   ../../../Class/vga256d.cpp \
				   ../../../Class/video.cpp \
				   ../../../Class/video_scale.cpp \
				   ../../../Class/video_scale_hqNx.cpp \
				   ../../../Class/xmas.cpp

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

