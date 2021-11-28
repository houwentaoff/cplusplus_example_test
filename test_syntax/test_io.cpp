#include "test_io.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
istream &TEST_IO::test_iostream(istream &ist)
{
    string str;
    while (ist>>str) {
        cout<<str<< endl;
        cout << flush;/* 刷新缓冲区 */
        cout << ends;/* 输出一个空字符，然后刷新缓冲区 */
    }
    ist.clear();
    return ist;
}
void TEST_IO::test_stringstream() {
    string path = "persion.txt";
    vector<Persion> persions;
    stringstream ss;
    ifstream ifile;// (path);

    ifile.open(path);
    if (!ifile) {
       // cout << "file open err" << endl;
        cerr << "Error: " << strerror(errno);

    }
    string line, phone;
    while (getline(ifile, line)) {
        Persion per;
        //stringstream ss(line);
        ss.str(line);
        ss >> per.name;
        while (ss >> phone) {
            per.phones.push_back(phone);
        }
        ss.clear();
        persions.push_back(per);
    }
    /* dump persions */
    for (vector<Persion>::iterator it = persions.begin(); it!=persions.end(); it++)
    {
        cout << it->name << endl;
        for (vector<string>::iterator itt = it->phones.begin();
            itt!= it->phones.end();
            itt++)
        {
            cout << *itt<<" ";
        }
        cout << endl;
    }
}
