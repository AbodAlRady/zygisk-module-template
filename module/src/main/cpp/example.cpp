#include <zygisk.hpp>
#include <cstring>

using zygisk::Api;
using zygisk::AppSpecializeArgs;

class MyModule : public zygisk::ModuleBase {
public:
    void onLoad(Api *api, const uint16_t *process_name) override {
        this->api = api;
    }

    void preAppSpecialize(AppSpecializeArgs *args) override {
        const char *process = api->getProcessName();
        if (process && strcmp(process, "com.miniclip.eightballpool") == 0) {
            api->setOption(zygisk::Option::FORCE_DENYLIST_UNMOUNT);
        }
    }
private:
    Api *api;
};

REGISTER_ZYGISK_MODULE(MyModule)
