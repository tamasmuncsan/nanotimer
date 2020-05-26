#include <napi.h>
#include "plf_nanotimer.h"

class NativeAddon : public Napi::ObjectWrap<NativeAddon> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        NativeAddon(const Napi::CallbackInfo& info);

    private:
        plf::nanotimer _timer;
        Napi::Value MillisecondDelay(const Napi::CallbackInfo& info);
        Napi::Value MicrosecondDelay(const Napi::CallbackInfo& info);
        Napi::Value NanosecondDelay(const Napi::CallbackInfo& info);
        Napi::Value GetElapsedMs(const Napi::CallbackInfo& info);
        Napi::Value GetElapsedUs(const Napi::CallbackInfo& info);
        Napi::Value GetElapsedNs(const Napi::CallbackInfo& info);
        Napi::Value Start(const Napi::CallbackInfo& info);
};