#pragma once
#include <istream>
#include <ostream>
#include <vector>

using namespace std;
class Persion {
public:
    string name;
    vector<string> phones;
};
class TEST_IO
{
public:
     istream &test_iostream( istream &ist);
     void test_stringstream();
};

