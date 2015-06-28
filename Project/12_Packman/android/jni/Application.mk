
# Uncomment this if you're using STL in your project
# See CPLUSPLUS-SUPPORT.html in the NDK documentation for more information
# APP_STL := stlport_static 

# APP_ABI := armeabi armeabi-v7a x86
APP_OPTIM := release
APP_ABI := armeabi
APP_PLATFORM := android-19
APP_STL := gnustl_static
APP_CPPFLAGS += -fexceptions
APP_CPPFLAGS += -std=c++11 -fsigned-char  -fpermissive
LOCAL_CFLAGS += -O3