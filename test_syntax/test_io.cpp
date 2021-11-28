#include "test_io.h"
#include <iostream>
#include <string>
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
