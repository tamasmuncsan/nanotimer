// Copyright 2020 Tamas Muncsan

#ifndef SRC_ADDON_H_
#define SRC_ADDON_H_

#include <napi.h>
#include "../src/plf_nanotimer.h"

class NativeAddon : public Napi::ObjectWrap<NativeAddon> {
 public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    explicit NativeAddon(const Napi::CallbackInfo& info);

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

#endif  // SRC_ADDON_H_
