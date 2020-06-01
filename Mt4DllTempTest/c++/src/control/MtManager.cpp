#include <src/control/MtManager.h>

#include <library/system/Console.hpp>


MtManager::MtManager()
{
    m_manager = m_managerFactory.Create(ManAPIVersion);

    m_manager->Connect("mttest.zhaodaishu.com");
    m_manager->Login(1, "manager");
}

MtManager* MtManager::m_instance = new MtManager();

MtManager* MtManager::getInstance()
{
    return m_instance;
}

deque<string> MtManager::getGroupList()
{
    int groupCount = 0;
	ConGroup* congroupList = m_manager->GroupsRequest(&groupCount);

    

    deque<string> groupList;
	if (congroupList != NULL && groupCount != 0)
	{
        for(int i = 0; i > groupCount; i++)
        {
            groupList.push_back(congroupList[i].group);
        }
	}

    Console::out("MtManager::getGroupList groupCount = ", groupList.size());

    m_manager->MemFree(congroupList);

    return std::move(groupList);
}
