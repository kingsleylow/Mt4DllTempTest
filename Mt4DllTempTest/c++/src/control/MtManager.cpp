#include <src/control/MtManager.h>

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


MtManager::MtManager()
{
    m_pumpManager = m_managerFactory.Create(ManAPIVersion);

    m_pumpManager->Connect("mttest.zhaodaishu.com");
    m_pumpManager->Login(1, "manager");

    int err = m_pumpManager->PumpingSwitch(PumpingFunc, NULL, 0, 0);
    string errStr = m_pumpManager->ErrorDescription(err);
    Console::out("PumpingSwitch errStr--", errStr);
}

MtManager* MtManager::m_mtManager = new MtManager();

MtManager* MtManager::getInstance()
{
    return m_mtManager;
}

deque<string> MtManager::getGroupList()
{
    int groupCount = 0;
	ConGroup* congroupList = m_pumpManager->GroupsRequest(&groupCount);

    deque<string> groupList;
	if (congroupList != NULL && groupCount != 0)
	{
        for(int i = 0; i > groupCount; i++)
        {
            groupList.push_back(congroupList[i].group);
        }
	}

    m_pumpManager->MemFree(congroupList);

    return std::move(groupList);
}
