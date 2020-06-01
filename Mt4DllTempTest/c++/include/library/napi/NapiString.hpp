#pragma once


#include <napi.h>

#include <string>
#include <deque>

#include <iostream>

using namespace std;


class NapiString
{
private:
    napi_env m_env;
    string m_value;
    

public:
	NapiString(napi_env env, const Napi::Value& param)
    {
        m_env = env;
        m_value = param.As<Napi::String>().Utf8Value();
    }

    NapiString(napi_env env, string value)
    {
        m_env = env;
        m_value = value;
    }

public:
    void setValue(string value)
    {
        m_value = value;
    }

public:
    string toNativeString()
    {
        return m_value;
    }

    Napi::String toJsString()
    {
        return Napi::String::New(m_env, m_value);
    }
};