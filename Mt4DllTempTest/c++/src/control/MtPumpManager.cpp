#include <src/control/MtPumpManager.h>

#include <library/system/Console.hpp>

void __stdcall PumpingFunc(int code)
{
    Console::out("PumpingFunc---- ", code);
	switch(code)
	{
	case PUMP_UPDATE_SYMBOLS:
		{
			

			break;
		}
	default: break;
	}
}


MtPumpManager::MtPumpManager()
{
    m_pumpManager = m_managerFactory.Create(ManAPIVersion);

    m_pumpManager->Connect("mttest.zhaodaishu.com");
    m_pumpManager->Login(1, "manager");

    int err = m_pumpManager->PumpingSwitch(PumpingFunc, NULL, 0, 0);
    string errStr = m_pumpManager->ErrorDescription(err);
    Console::out("PumpingSwitch errStr--", errStr);
}

MtPumpManager* MtPumpManager::m_instance = new MtPumpManager();

MtPumpManager* MtPumpManager::getInstance()
{
    return m_instance;
}

deque<string> MtPumpManager::getGroupList()
{
    int groupCount = 0;
	ConGroup* congroupList = m_pumpManager->GroupsRequest(&groupCount);

    deque<string> groupList;
	if (congroupList != NULL && groupCount != 0)
	{
        for(int i = 0; i < groupCount; i++)
        {
            groupList.push_back(congroupList[i].group);
        }
	}

    m_pumpManager->MemFree(congroupList);

    return std::move(groupList);
}
