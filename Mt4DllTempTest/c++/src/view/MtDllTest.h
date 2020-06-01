#pragma once

#include<library/napi/NapiType.h>

class MtDllTest
{
public:
    static Napi::Array pumpManagerTest(const Napi::CallbackInfo& info);
    static Napi::Array managerTest(const Napi::CallbackInfo& info);

};