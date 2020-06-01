#pragma once


#include <napi.h>

#include <string>
#include <deque>

#include <iostream>

using namespace std;

#include<library/napi/NapiArray.h>

class NapiArray;
class NapiObject
{
private:
    napi_env m_env;
    Napi::Object m_value;
    

public:
	NapiObject(napi_env env, const Napi::Value& param);

    NapiObject(napi_env env);

public:
    int getInt(string feild);
    double getDouble(string feild);
    bool getBool(string feild);
    string getString(string feild);
    NapiObject getNapiObject(string feild);
    NapiArray getNapiArray(string feild);

public:
    void set(string feild, int value);
    void set(string feild, double value);
    void set(string feild, bool value);
    void set(string feild, string value);
    void set(string feild, NapiObject value);
    void set(string feild, NapiArray value);

public:
    Napi::Object toJsObject();
};