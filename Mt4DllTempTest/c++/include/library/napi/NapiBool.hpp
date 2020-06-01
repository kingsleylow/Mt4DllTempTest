#pragma once


#include <napi.h>

#include <string>
#include <deque>

#include <iostream>

using namespace std;


class NapiBool
{
private:
    napi_env m_env;
    bool m_value;
    

public:
	NapiBool(napi_env env, const Napi::Value& param)
    {
        m_env = env;
        m_value = param.As<Napi::Boolean>().Value();
    }

    NapiBool(napi_env env, bool value)
    {
        m_env = env;
        m_value = value;
    }

public:
    void setValue(bool value)
    {
        m_value = value;
    }

public:
    bool toNativeBool()
    {
        return m_value;
    }

    Napi::Boolean toJsBool()
    {
        return Napi::Boolean::New(m_env, m_value);
    }
};