#include <jni.h>
#include <android/log.h>
#include "sciter-x.h"

#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, "KRYNET_NATIVE", __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,  "KRYNET_NATIVE", __VA_ARGS__)

extern "C"
JNIEXPORT void JNICALL
Java_com_krynet_MainActivity_startSciter(JNIEnv* env, jobject thiz)
{
    // 1. Enforce strict privacy-first execution constraints
    SciterSetOption(NULL, SCITER_SET_SCRIPT_RUNTIME_FEATURES, ALLOW_SOCKET_IO);
    SciterSetOption(NULL, SCITER_SET_GFX_LAYER, GFX_LAYER_SOFTWARE);

#ifdef DEBUG
    SciterSetOption(NULL, SCITER_SET_DEBUG_MODE, TRUE);
#endif

    // 2. Instantiate the Sciter HWINDOW context attached to the host Java Activity instance
    // Passing 'thiz' as the parent binds Sciter's lifecycle to the Android View Surface
    HWINDOW hwnd = SciterCreateWindow(
        SW_CHILD, 
        nullptr, 
        nullptr, 
        static_cast<void*>(thiz)
    );

    if (!hwnd) {
        LOGE("Fatal: Failed to attach Sciter window context to Android surface.");
        return;
    }

    // 3. Load the secure web client bundle using Sciter-safe character sequences
    BOOL success = SciterLoadUrl(hwnd, WSTR("https://krynet.ai"));
    
    if (!success) {
        LOGE("Error: Failed to route network request to target gateway.");
    } else {
        LOGI("Krynet Client engine initialized successfully.");
    }
}
