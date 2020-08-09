/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	void replaceSpace(char* str, int length) {
		if (str == nullptr || length == 0)
		{
			return;
		}
		int blankcnt = 0;
		for (int i = 0; i < length; i++)
		{
			if (str[i] == ' ')
			{
				blankcnt++;
			}
		}
		if (blankcnt == 0)
		{
			return;
		}
		int newlength = length + 2 * blankcnt;
		for (int i = length; i >= 0; i--)
		{
			if (str[i] == ' ')
			{
				str[newlength--] = '0';
				str[newlength--] = '2';
				str[newlength--] = '%';

			}
			else
			{
				str[newlength--] = str[i];
			}
		}
		return;
	}
};