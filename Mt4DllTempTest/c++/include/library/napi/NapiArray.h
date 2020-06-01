#pragma once


#include <napi.h>

#include<library/napi/NapiObject.h>

class NapiObject;
class NapiArray
{
private:
    napi_env m_env;
    Napi::Array m_value;
    

public:
	NapiArray(napi_env env, const Napi::Value& param);

    NapiArray(napi_env env);

public:
    int getInt(int index);
    double getDouble(int index);
    bool getBool(int index);
    string getString(int index);
    NapiObject getNapiObject(int index);
    NapiArray getNapiArray(int index);

public:
    void set(int index, int value);
    void set(int index, double value);
    void set(int index, bool value);
    void set(int index, string value);
    void set(int index, NapiObject value);
    void set(int index, NapiArray value);

public:
    Napi::Array toJsArray();
};