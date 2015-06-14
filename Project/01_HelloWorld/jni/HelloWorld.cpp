#include <jni.h>
#include "com_example_helloworld_MainActivity.h"

JNIEXPORT jstring JNICALL Java_com_example_helloworld_MainActivity_getMessage
  (JNIEnv *env, jobject){
	return env->NewStringUTF("Hello from native code!");
}
