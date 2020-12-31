LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := GUIChan

LOCAL_SRC_FILES :=  src/actionevent.cpp \
					src/basiccontainer.cpp \
					src/cliprectangle.cpp \
					src/color.cpp \
					src/defaultfont.cpp \
					src/event.cpp \
					src/exception.cpp \
					src/focushandler.cpp \
					src/font.cpp \
					src/genericinput.cpp \
					src/graphics.cpp \
					src/gui.cpp \
					src/guichan.cpp \
					src/image.cpp \
					src/imagefont.cpp \
					src/inputevent.cpp \
					src/key.cpp \
					src/keyevent.cpp \
					src/keyinput.cpp \
					src/mouseevent.cpp \
					src/mouseinput.cpp \
					src/rectangle.cpp \
					src/selectionevent.cpp \
					src/truetypefont.cpp \
					src/widget.cpp \
					src/widgets/button.cpp \
					src/widgets/checkbox.cpp \
					src/widgets/container.cpp \
					src/widgets/dropdown.cpp \
					src/widgets/icon.cpp \
					src/widgets/imagebutton.cpp \
					src/widgets/label.cpp \
					src/widgets/listbox.cpp \
					src/widgets/radiobutton.cpp \
					src/widgets/scrollarea.cpp \
					src/widgets/slider.cpp \
					src/widgets/tab.cpp \
					src/widgets/tabbedarea.cpp \
					src/widgets/textbox.cpp \
					src/widgets/textfield.cpp \
					src/widgets/window.cpp \
					src/sdl/sdl.cpp \
					src/sdl/sdlgraphics.cpp \
					src/sdl/sdlimage.cpp \
					src/sdl/sdlimageloader.cpp \
					src/sdl/sdlinput.cpp
					
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../SD2_Module/SDL2/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../SD2_Module/SDL2_image
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)
						  

CXXFLAGS += -fexceptions 
APP_CPPFLAGS += fexceptions 

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_ttf SDL2_image

LOCAL_CFLAGS += -DGL_GLEXT_PROTOTYPES
LOCAL_LDLIBS := -ldl -lGLESv1_CM -lGLESv2 -llog -landroid

include $(BUILD_SHARED_LIBRARY)
