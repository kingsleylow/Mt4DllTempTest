#include<library/napi/NapiArray.h>



NapiArray::NapiArray(napi_env env, const Napi::Value& param)
{
    m_env = env;
    m_value = param.As<Napi::Array>();
}

NapiArray::NapiArray(napi_env env)
{
    m_env = env;
    m_value = Napi::Array::New(env);
}

int NapiArray::getInt(int index)
{
    return static_cast<Napi::Value>(m_value[index]).As<Napi::Number>().Int32Value();
}

double NapiArray::getDouble(int index)
{
    return static_cast<Napi::Value>(m_value[index]).As<Napi::Number>().DoubleValue();
}

bool NapiArray::getBool(int index)
{
    return static_cast<Napi::Value>(m_value[index]).As<Napi::Boolean>().Value();
}

string NapiArray::getString(int index)
{
    return static_cast<Napi::Value>(m_value[index]).As<Napi::String>().Utf8Value();
}

NapiObject NapiArray::getNapiObject(int index)
{
    return NapiObject(m_env, static_cast<Napi::Value>(m_value[index]));
}

NapiArray NapiArray::getNapiArray(int index)
{
    return NapiArray(m_env, static_cast<Napi::Value>(m_value[index]));
}

void NapiArray::set(int index, int value)
{
    m_value[index] = Napi::Number::New(m_env, value); 
}

void NapiArray::set(int index, double value)
{
    m_value[index] = Napi::Number::New(m_env, value); 
}

void NapiArray::set(int index, bool value)
{
    m_value[index] = Napi::Boolean::New(m_env, value); 
}

void NapiArray::set(int index, string value)
{
    m_value[index] = Napi::String::New(m_env, value); 
}

void NapiArray::set(int index, NapiObject value)
{
    m_value[index] = value.toJsObject(); 
}

void NapiArray::set(int index, NapiArray value)
{
    m_value[index] = value.toJsArray(); 
}

Napi::Array NapiArray::toJsArray()
{
    return m_value;
}