/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则按字典序打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

/*
 * 交换法 —— 回溯算法
 *
 * [a, [b, c]]
 * [b, [a, c]] [c, [b, a]]
 *
 * 如上，对字符串"abc"分割，每次固定一个字符为一部分，
 * 其他字符为另一部分，再将固定字符与其他字符进行交换，
 * 依次遍历每个字符，再进行回溯递归。
 * */

class Solution {
#if 0
public:
    vector<string> Permutation(string str) {
        if (str.size() == 0) return vector<string>(0, string(""));
        Permutation(str, 0);
        return vector<string>(res.begin(), res.end());

    }
private:
    void Permutation(string str, int start)
    {
        if (start == str.size()) 
        {
            res.insert(str);
            return;
        }
        for (int i = start; i < str.size(); i++)
        {
            //先交换
            swap(str[i], str[start]);
            //下一轮回溯
            Permutation(str, start + 1);
            swap(str[i], str[start]); //恢复
        }

    }

    set<string> res;
#endif
public:
    vector<string> Permutation(string str){
        if (str.size() == 0) return vector<string>(0, string(""));
        dfs(str, 0);
        return res;
    }
    void dfs(string str, int start)
    {
        if (start == str.size())
        {
            res.push_back(str);
            return;
        }
        set<char> dup;
        for (int i = start; i < str.size(); i++)
        {
            if(dup.find(str[i]) != dup.end()) //有重复的
            {
                continue;
            }
            dup.insert(str[i]);
            swap(str[i], str[start]);
            dfs(str, start + 1);
            swap(str[i], str[start]); //恢复交换

        }
    }
private:
    vector<string> res;
};

/*
递归解析：
终止条件： 当x = len(c) − 1时，代表所有位已固定（最后一位只有 11 种情况），则将当前组合c转化为字符串并加入res，并返回；
递推参数： 当前固定位 x ；
递推工作： 初始化一个 Set ，用于排除重复的字符；将第 x 位字符与[x, len - 1] 字符分别交换，并进入下层递归；
剪枝： 若 c[i]在 Set​ 中，代表其是重复字符，因此“剪枝”；
将 c[i] 加入 Set​ ，以便之后遇到重复字符时剪枝；
固定字符： 将字符 c[i] 和 c[x] 交换，即固定 c[i]为当前位字符；
开启下层递归： 调用 dfs(x + 1) ，即开始固定第 x + 1个字符；
还原交换： 将字符 c[i] 和 c[x] 交换（还原之前的交换）；
*/
