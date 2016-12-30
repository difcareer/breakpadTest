#include <jni.h>
#include "client/linux/handler/exception_handler.h"

bool dumpCallback(const google_breakpad::MinidumpDescriptor &descriptor, void *context,
                  bool succeeded) {
    printf("Dump path: %s\n", descriptor.path());
    return succeeded;
}

static google_breakpad::ExceptionHandler *exceptionHandler;

extern "C" {


JNIEXPORT void JNICALL
Java_com_andr0day_ndktest_NativeCrash_install(JNIEnv *env, jclass type) {
    google_breakpad::MinidumpDescriptor descriptor("/sdcard/");
    exceptionHandler = new google_breakpad::ExceptionHandler(descriptor, NULL, dumpCallback, NULL,
                                                             true, -1);
}


}
