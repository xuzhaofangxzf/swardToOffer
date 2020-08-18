//一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
#include <iostream>
#include <vector>
#include <unordered_map>
// #include <functional>
using namespace std;



class Solution {
public:
    //方法1: 哈希法
    void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
        unordered_map<int, int> map;
        int ret[2];
        for (int i = 0; i < data.size(); i++)
        {
            map[data[i]]++;
        }
        int i = 0;
        for (const int k : data)
        {
            if (map[k] == 1)
            {
                ret[i++] = k;
            }
            if (i == 2) break;
        }
        *num1 = ret[0];
        *num2 = ret[1];
        return;
    }
    //方法2: 位运算, 因为数组中其他元素都出现两次,假如只出现一次的两个数分别为x和y,故进行异或运算后,其他出现两次的数变为0,因为(n ^ n = 0, 0 ^ n = n, a ^ b ^ c = a ^(b ^ c)), 最终的结果为x ^ y
    //假定bitmask = x ^ y，即x ^ y 表示x与y不同的位都置为1，利用 bitmask & (-bitmask)可以保留最后一位的1，则最后一位的1要么来自于x，要么来自于y，用该位作为标志，将数组中的数分成两类，1类是该位为1，另一类是该位不为1。
    //即判定(d & diff)是否等于1，来判断。这样就将x 与y分离到两类中去了。最终得到的肯定是x与y其中一个。
    void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
    {
        int bitmask = 0;
        for (const int d : data) bitmask ^= d; //得到x ^ y
        int diff = bitmask & (-bitmask);
        int xory = 0;
        for (const int d: data)
        {
            if ((d & diff) != 0) //分成两类，1类是改位为1，一类是该位不为1
            {
                xory ^= d; //与逐个元素再重新异或,为了找到x或者y
            }
            
        }
        *num1 = xory;
        *num2 = xory ^ bitmask;
        return;
    }
};