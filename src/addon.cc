// Copyright 2020 Tamas Muncsan

#include "../src/plf_nanotimer.h"
#include "../src/addon.h"

NativeAddon::NativeAddon(const Napi::CallbackInfo& info)
: Napi::ObjectWrap<NativeAddon>(info) { }

Napi::Value NativeAddon::MillisecondDelay(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "You need to pass an argument!")
          .ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(
          env,
          "You need to pass a double value as a callback!")
        .ThrowAsJavaScriptException();

        return env.Null();
    }

    double delayTime = info[0].As<Napi::Number>().DoubleValue();
    plf::millisecond_delay(delayTime);

    return env.Null();
}

Napi::Value NativeAddon::MicrosecondDelay(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "You need to pass an argument!")
          .ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "You need to pass a number value!")
          .ThrowAsJavaScriptException();
        return env.Null();
    }

    double delayTime = info[0].As<Napi::Number>().DoubleValue();

    plf::microsecond_delay(delayTime);
    return env.Null();
}

Napi::Value NativeAddon::NanosecondDelay(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
        Napi::TypeError::New(env, "You need to pass an argument!")
          .ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "You need to pass a number value!")
          .ThrowAsJavaScriptException();
        return env.Null();
    }

    double delayTime = info[0].As<Napi::Number>().DoubleValue();

    plf::nanosecond_delay(delayTime);
    return env.Null();
}

Napi::Value NativeAddon::Start(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    this->_timer.start();

    return env.Null();
}

Napi::Value NativeAddon::GetElapsedMs(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  double results = this->_timer.get_elapsed_ms();

  return Napi::Number::New(env, results);
}

Napi::Value NativeAddon::GetElapsedUs(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  double results = this->_timer.get_elapsed_us();

  return Napi::Number::New(env, results);
}

Napi::Value NativeAddon::GetElapsedNs(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  double results = this->_timer.get_elapsed_ns();

  return Napi::Number::New(env, results);
}

Napi::Object NativeAddon::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "NativeAddon", {
    InstanceMethod("millisecondDelay", &NativeAddon::MillisecondDelay),
    InstanceMethod("microsecondDelay", &NativeAddon::MicrosecondDelay),
    InstanceMethod("nanosecondDelay", &NativeAddon::NanosecondDelay),
    InstanceMethod("getElapsedMs", &NativeAddon::GetElapsedMs),
    InstanceMethod("getElapsedUs", &NativeAddon::GetElapsedUs),
    InstanceMethod("getElapsedNs", &NativeAddon::GetElapsedNs),
    InstanceMethod("start", &NativeAddon::Start)
  });

  exports.Set("Nanotimer", func);
  return exports;
}
