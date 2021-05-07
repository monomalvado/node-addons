#include <iostream>
#include <node.h>
#include <v8.h>

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::Integer;
using v8::Value;
using v8::String;
using v8::Module;

int main() {
    std::cout << "Testing\n";
    return 0;
}

void MainWrapper(const FunctionCallbackInfo<Value> &info) {
    Isolate* isolate = info.GetIsolate();
    const int result = main();
    info.GetReturnValue().Set(Integer::New(isolate, result));
}

void HelloWrapper( const FunctionCallbackInfo<Value>& info ) {
    auto isolate = info.GetIsolate();
    info.GetReturnValue().Set(String::NewFromUtf8(isolate, "Hello, World!").ToLocalChecked());
}

void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "main", MainWrapper);
    NODE_SET_METHOD(exports, "hello", HelloWrapper);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)