#include <string>
#include <map>
#include "test_stl.h"
#include <iostream>
using namespace std;
/* ��������map���� 
 * multimap �ؼ��ֿ��ظ���map
 * unordered_map ���򱣴��map
 * ����������֧��˳������λ����صĲ�����
 * push_front push_back
 */
bool Test_STL::test_map()
{
	map<string, int>words_count;
	string word;
	int count = 10;
	while (cin >> word) {
		words_count[word]++;
		if (count-- == 0) {
			break;
		}
	}
	for (map<string, int>::iterator it = words_count.begin(); it != words_count.end(); it++ )
	{
		cout << it->first << ":" << it->second << endl;
	}
	return true;
}