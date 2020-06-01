#pragma once


#include <napi.h>

#include <string>
#include <deque>

#include <iostream>

using namespace std;


class NapiDouble
{
private:
    napi_env m_env;
    double m_value;
    

public:
	NapiDouble(napi_env env, const Napi::Value& param)
    {
        m_env = env;
        m_value = param.As<Napi::Number>().DoubleValue();
    }

    NapiDouble(napi_env env, double value)
    {
        m_env = env;
        m_value = value;
    }

public:
    void setValue(double value)
    {
        m_value = value;
    }

public:
    int toNativeDouble()
    {
        return m_value;
    }

    Napi::Number toJsDouble()
    {
        return Napi::Number::New(m_env, m_value);
    }
};