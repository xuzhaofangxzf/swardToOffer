/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //借鉴插入排序的算法: 从左到右遍历数组,找到奇数,然后将奇数插入到前面,遇到偶数就继续往前,事件复杂度O(n)
    void reOrderArray(vector<int> &array) {
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] & 1 == 1) //奇数向前插入
            {
                int val = array[i]; //将该数存储起来
                while (i > 0 && (array[i - 1] & 1) == 0)
                {
                    array[i] = array[i - 1];
                    i--;
                }
                array[i] = val;
            }
        }
    }
};