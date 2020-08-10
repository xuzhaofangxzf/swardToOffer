/*
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
*/

#include <iostream>
using namespace std;

class Solution {
public:
    //递归
    int Fibonacci(int n) {
        if (n == 0 || n == 1)
        {
            return n;
        }
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
    //DP
    int Fibonacci(int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }
        int* aFibval = new int[n + 1];
        aFibval[0] = 0;
        aFibval[1] = 1;
        for (int i = 2; i <= n; i ++)
        {
            aFibval[i] = aFibval[i - 1] + aFibval[i - 2];
        }
        return aFibval[n];
    }
    //滚动数组
    int Fibonacci(int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }
        int pre = 0;
        int cur = 1;
        int res = 0;
        for (int i = 2; i <= n; i++)
        {
            res = pre + cur;
            pre = cur;
            cur = res;
        }
        return res;
    }
};