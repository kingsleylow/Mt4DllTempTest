#pragma once



#include <string>
#include <deque>

#include <iostream>

using namespace std;


class Console
{
public:
	static string readString()
	{
		string str;
		cin >> str;
		return move(str);
	}

    template<typename T, typename ... Args>
    static void out(T data, Args ... dataList)
    {
        cout<< data << " ";
        out(dataList...);
    }

    template<typename T>
    static void out(T data)
    {
        cout<<data<<endl;
    }
};