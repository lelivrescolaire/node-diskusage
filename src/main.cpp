#include "diskusage.h"

#include <napi.h>
#include <stdexcept>

static Napi::Object getDiskUsage(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  if (info.Length() != 1) {
    throw Napi::Error::New(env, "getDiskUsage invalid number of arguments");
  }
  if (!info[0].IsString()) {
    throw Napi::Error::New(env, "getDiskUsage must be called with a single path argument");
  }

  Napi::String path = info[0].As<Napi::String>();
  std::string pathText = path;

  DiskUsage usage = GetDiskUsage(pathText.c_str());

  Napi::Object result = Napi::Object::New(env);
  result.Set("available", Napi::Number::New(env, static_cast<double>(usage.available)));
  result.Set("free", Napi::Number::New(env, static_cast<double>(usage.free)));
  result.Set("total", Napi::Number::New(env, static_cast<double>(usage.total)));
  return result;
}

static Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set("getDiskUsage", Napi::Function::New(env, getDiskUsage));
  return exports;
}

NODE_API_MODULE(diskusage, Init)

