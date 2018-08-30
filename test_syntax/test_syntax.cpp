/*
 * =====================================================================================
 *       Copyright (c), 2013-2020, xxx.
 *       Filename:  test_syntax.cpp
 *
 *    Description:  g++ *.cpp -std=c++11 -lpthread
 *         Others:
 *
 *        Version:  1.0
 *        Created:  08/29/2018 10:42:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Joy. Hou (hwt), 544088192@qq.com
 *   Organization:  xxx
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <typeinfo>

#include <thread>

using namespace std;

void test_for()
{
    string str = "hello, world";
    for (char c : str)
    {
        cout<<c<<endl;
    }

    int array[]={1,2,3,4,5};
    for (auto i : array)
    {
        cout<<i<<endl;
    }
    //stl
    vector<string> str_vec = {"name1", "name2", "name3", "name4"};
    //legacy 
    vector<int>old_vec;
    old_vec.push_back(11);
    old_vec.push_back(22);
    old_vec.push_back(33);
    for (vector<int>::iterator it = old_vec.begin();
            it != old_vec.end();
            it++)
    {
        cout<<*it<<":"<<hex<< *it <<" "<<dec;
    }
    //new style
    //auto -> string
    // & -> 可以修改容器内容
    for (auto & it : str_vec)
    {
        cout << "it type:"<< typeid(it).name() << endl;
        cout << it.c_str() <<" "<< it <<endl;
    }
    for (auto it = str_vec.begin();
            it != str_vec.end();
            it++)
    {
        cout << *it;
    }
    //legacy style
    for (vector<string>::iterator it = str_vec.begin();
            it != str_vec.end();
            it++)
    {
        //引用赋值
        string s = *it;
        //it->c_str() == (*it).c_str()
        cout<<" "<<s<<" "<<it->c_str()<<" "<< *it <<" "<< (*it).c_str();
    }
    cout<<endl;
    //map -> tuple
    map<string, int>names_key = {{"Font32.DZT", 32}, {"Font41", 41}, {"Font43", 43}, {"Font52", 52}};
    //legacy style
    map<string, int>nandks;
    nandks["aaa"] = 1;
    nandks["aaab"] = 2;
    nandks["aaab"] = 3;

    nandks.insert(pair<string, int>("aws", 89));
    nandks.insert(pair<string, int>("aaws", 89));

    //new style
    for (auto & it : names_key)
    {
        cout<<it.first << "\t" << it.second <<endl;
    }

}
void *func(void *data)
{
    int count = 0;
    while(1)
    {
        cout << count++ <<endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return NULL;
}
//c++11 thread
void test_thread()
{
    std::thread tid;
    tid = thread(func, nullptr);
    tid.detach();
}
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] )
{
    test_for();
    test_thread();
    while (1)
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
    return 0;
}

