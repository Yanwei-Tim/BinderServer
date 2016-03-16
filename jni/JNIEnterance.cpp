#include "com_example_testbinder_JNIEnterance.h"

extern int test();

JNIEXPORT void JNICALL Java_com_example_testbinder_JNIEnterance_testBinder
  (JNIEnv * env, jobject obj)
{
	test();
}

