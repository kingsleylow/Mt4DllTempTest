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
    ~MtManager();

public:
    static MtManager* m_instance;
    static MtManager* getInstance();

private:
    CManagerFactory* m_managerFactory;
    CManagerInterface* m_manager;

public:
    deque<string> getGroupList();
};