#include "test_io.h"
#include <iostream>
#include <string>
istream &TEST_IO::test_iostream(istream &ist)
{
    string str;
    while (ist>>str) {
        cout<<str<< endl;
        cout << flush;/* ˢ�»����� */
        cout << ends;/* ���һ�����ַ���Ȼ��ˢ�»����� */
    }
    ist.clear();
    return ist;
}
