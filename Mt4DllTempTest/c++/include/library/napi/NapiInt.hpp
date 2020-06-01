#pragma once


#include <napi.h>

#include <string>
#include <deque>

#include <iostream>

using namespace std;


class NapiInt
{
private:
    napi_env m_env;
    int m_value;
    

public:
	NapiInt(napi_env env, const Napi::Value& param)
    {
        m_env = env;
        m_value = param.As<Napi::Number>().Int32Value();
    }

    NapiInt(napi_env env, int value)
    {
        m_env = env;
        m_value = value;
    }

public:
    void setValue(int value)
    {
        m_value = value;
    }

public:
    int toNativeInt()
    {
        return m_value;
    }

    Napi::Number toJsInt()
    {
        return Napi::Number::New(m_env, m_value);
    }
};