// Copyright 2020 Tamas Muncsan

#include <napi.h>
#include "../src/addon.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    NativeAddon::Init(env, exports);
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
