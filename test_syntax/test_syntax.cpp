/*
 * =====================================================================================
 *       Copyright (c), 2013-2020, xxx.
 *       Filename:  test_syntax.cpp
 *
 *    Description:  g++ *.cpp -std=c++11
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
    //new style
    //auto -> string
    // & -> 可以修改容器内容
    for (auto & it : str_vec)
    {
        cout << typeid(it).name() << endl;
        cout << it.c_str() <<" "<< it <<endl;
    }
    for (auto it = str_vec.begin();
            it != str_vec.end();
            it++)
    {
        cout << *it;
    }
    //old style
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

    for (auto & it : names_key)
    {
        cout<<it.first << "\t" << it.second <<endl;
    }
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
    return 0;
}

