#include<library/napi/NapiObject.h>



NapiObject::NapiObject(napi_env env, const Napi::Value& param)
{
    m_env = env;
    m_value = param.ToObject();
}

NapiObject::NapiObject(napi_env env)
{
    m_env = env;
    m_value = Napi::Object::New(env);
}

int NapiObject::getInt(string feild)
{
    return m_value.Get(static_cast<Napi::Value>(Napi::String::New(m_env, feild))).As<Napi::Number>().Int32Value();
}

double NapiObject::getDouble(string feild)
{
    return m_value.Get(static_cast<Napi::Value>(Napi::String::New(m_env, feild))).As<Napi::Number>().DoubleValue();
}

bool NapiObject::getBool(string feild)
{
    return m_value.Get(static_cast<Napi::Value>(Napi::String::New(m_env, feild))).As<Napi::Boolean>().Value();
}

string NapiObject::getString(string feild)
{
    return m_value.Get(static_cast<Napi::Value>(Napi::String::New(m_env, feild))).As<Napi::String>().Utf8Value();
}

NapiObject NapiObject::getNapiObject(string feild)
{
    return NapiObject(m_env, m_value.Get(static_cast<Napi::Value>(Napi::String::New(m_env, feild))));
}

NapiArray NapiObject::getNapiArray(string feild)
{
    return NapiArray(m_env, m_value.Get(static_cast<Napi::Value>(Napi::String::New(m_env, feild))));
}

void NapiObject::set(string feild, int value)
{
    m_value.Set(Napi::String::New(m_env, feild), value);
}

void NapiObject::set(string feild, double value)
{
    m_value.Set(Napi::String::New(m_env, feild), value);
}

void NapiObject::set(string feild, bool value)
{
    m_value.Set(Napi::String::New(m_env, feild), value);
}

void NapiObject::set(string feild, string value)
{
    m_value.Set(Napi::String::New(m_env, feild), value);
}

void NapiObject::set(string feild, NapiObject value)
{
    m_value.Set(Napi::String::New(m_env, feild), value.toJsObject());
}

void NapiObject::set(string feild, NapiArray value)
{
    m_value.Set(Napi::String::New(m_env, feild), value.toJsArray());
}


Napi::Object NapiObject::toJsObject()
{
    return m_value;
}