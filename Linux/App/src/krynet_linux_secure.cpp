#include <sciter-x.h>
#include <sciter-x-window.hpp>

class KrynetApp : public sciter::window {
public:
    KrynetApp() : sciter::window(SW_TITLEBAR | SW_RESIZEABLE | SW_CONTROLS | SW_MAIN) {}

    bool init() {
        if (!SciterSetOption(NULL, SCITER_SET_GFX_LAYER, GFX_LAYER_SOFTWARE)) return false;
        if (!SciterSetOption(NULL, SCITER_SET_SCRIPT_RUNTIME_FEATURES, ALLOW_SOCKET_IO)) return false;
        if (!load_url(WSTR("https://krynet.ai"))) return false;
        expand();
        return true;
    }
};

int main() {
    KrynetApp app;
    if (!app.init()) return 1;
    return app.run_app();
}
