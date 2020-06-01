#pragma once 

#include<Mt4/MT4ManagerAPI.h>
#include<iostream>
#include<string>
#include<deque>

using namespace std;

class MtManager
{
public:
    MtManager();

public:
    static MtManager* m_mtManager;
    static MtManager* getInstance();

private:
    CManagerFactory m_managerFactory;
    CManagerInterface* m_pumpManager;

public:
    deque<string> getGroupList();
};