#pragma once 

#include<Mt4/MT4ManagerAPI.h>
#include<iostream>
#include<string>
#include<deque>

using namespace std;

class MtPumpManager
{
public:
    MtPumpManager();

public:
    static MtPumpManager* m_instance;
    static MtPumpManager* getInstance();

private:
    CManagerFactory m_managerFactory;
    CManagerInterface* m_pumpManager;

public:
    deque<string> getGroupList();
};