#include <jni.h>
#include <string>

void crash() {
    volatile int *a = (int *) (NULL);
    *a = 1;
}

extern "C" {

jstring
Java_com_andr0day_ndktest_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */) {
    crash();
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


}

