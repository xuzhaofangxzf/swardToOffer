/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    //1: 哈希表法
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        unordered_map<int, int> map;
        for (int i = 0; i < numbers.size(); i++)
        {
            map[numbers[i]]++;
        }
        for (int i = 0; i < numbers.size(); i++)
        {
            if (map[numbers[i]] > numbers.size() / 2)
            {
                return numbers[i];
            }
        }
        return 0;
    }
    //2: 排序法
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        sort(numbers.begin(), numbers.end());
        int cond = numbers[numbers.size() / 2];
        int cnt = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == cond)
            {
                cnt++;
            }
        }
        if (cnt > numbers.size() / 2)
        {
            return cond;
        }
        return 0;
    }

    //思想就是：如果两个数不相等，就消去这两个数，最坏情况下，每次消去一个众数和一个非众数，那么如果存在众数，最后留下的数肯定是众数。
    /*
    具体做法：

    1. 初始化：候选人cond = -1， 候选人的投票次数cnt = 0
    2. 遍历数组，如果cnt=0， 表示没有候选人，则选取当前数为候选人，++cnt
    3. 否则，如果cnt > 0, 表示有候选人，如果当前数=cond，则++cnt，否则--cnt
    4. 直到数组遍历完毕，最后检查cond是否为众数
    */
   int MoreThanHalfNum_Solution(vector<int> numbers)
   {
       int cond = -1;
       int cnt = 0;
       for (int i = 0; i < numbers.size(); i++)
       {
            if (cnt == 0)
            {
                cond = numbers[i];
                cnt++;
            }
            else
            {
                if (cond == numbers[i]) cnt++;
                else cnt--;
            }
       }
       cnt = 0;
       for (const int num : numbers)
       {
           if (num == cond) cnt++;
       }
       if (cnt > numbers.size() / 2) return cond;
       return 0;
   }
};