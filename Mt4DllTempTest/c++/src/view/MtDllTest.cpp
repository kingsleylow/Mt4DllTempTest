#include <src/view/MtDllTest.h>

#include <library/system/Console.hpp>

#include<src/control/MtManager.h>
#include<src/control/MtPumpManager.h>

Napi::Array MtDllTest::pumpManagerTest(const Napi::CallbackInfo& info)
{
    NapiArray groupArray(info.Env());
    
    deque<string> groupList = MtPumpManager::getInstance()->getGroupList();
    for(int i = 0; i < groupList.size(); i++)
    {
        groupArray.set(i, groupList[i]);
    }

    return groupArray.toJsArray();
}

Napi::Array MtDllTest::managerTest(const Napi::CallbackInfo& info)
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

  exports.Set("pumpManagerTest", Napi::Function::New(env, MtDllTest::pumpManagerTest));
  exports.Set("managerTest", Napi::Function::New(env, MtDllTest::managerTest));

  return exports;
}

NODE_API_MODULE(MtDllTest, MtDllTestFunRegister)