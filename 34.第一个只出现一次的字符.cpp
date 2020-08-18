/*
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数）
*/
//暴力解法：用哈希表存储每个字符出现的次数，然后再从头遍历，查看该字符的次数是不是1，如果是1就返回，由于字母只有26个，故可以创建26的数组
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> map;
        //map.resize(26);
        for (const char c : str)
        {
            map[c]++;
        }
        for (int i = 0; i < str.size(); i++)
        {
            if (map[str[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
    //方法2：使用bitset节省空间，创建两个bitset1，bitset2，bitset1表示如果出现就置1，bitset2表示出现次数超过1的就置1
    int FirstNotRepeatingChar(string str)
    {
        bitset<128> b1, b2;
        for (const char ch : str)
        {
            if (b1[ch] == 1)
            {
                b2[ch] = 1;
            }
            else
            {
                b1[ch] = 1;
            }
        }

        for (int i = 0; i < str.size(); i++)
        {
            if (b1[str[1]] == 1 && b2[str[i]] == 0)
            {
                return i;
            }
        }
        return -1;
    }
};