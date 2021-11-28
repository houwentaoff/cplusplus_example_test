#include <string>
#include <map>
#include "test_stl.h"
#include <iostream>
using namespace std;
/* 关联容器map测试 
 * multimap 关键字可重复的map
 * unordered_map 无序保存的map
 * 关联容器不支持顺序容器位置相关的操作如
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