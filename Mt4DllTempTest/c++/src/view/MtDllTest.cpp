#include <src/view/MtDllTest.h>

#include <library/system/Console.hpp>

#include<src/control/MtManager.h>


Napi::Array MtDllTest::pumpTest(const Napi::CallbackInfo& info)
{
    NapiArray groupArray(info.Env());
    
    deque<string> groupList = MtManager::getInstance()->getGroupList();
    for(int i = 0; i < groupList.size(); i++)
    {
        groupArray.set(i, groupList[i]);
    }

    return groupArray.toJsArray();
}

Napi::Object MtDllTestFunRegister(Napi::Env env, Napi::Object exports)
{

  exports.Set("pumpTest", Napi::Function::New(env, MtDllTest::pumpTest));

  return exports;
}

NODE_API_MODULE(MtDllTest, MtDllTestFunRegister)