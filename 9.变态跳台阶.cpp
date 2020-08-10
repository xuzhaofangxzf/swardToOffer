#include <iostream>
#include <vector>
using namespace std;
/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 0 || number == 1)
        {
            return 1;
        }
        vector<int> res(number + 1, 0);
        res[0] = 1;
        res[1] = 1;
        for (int i = 2; i <= number; i++)
        {
            for(int j = 0; j < i; j++)
            {
                res[i] += res[j];
            }
        }
        return res[number];
    }
    //优化,f(n) = f(n - 1) + f(n - 2) + ... + f(0)
    //f(n) = 2 * f(n - 1)
    int jumpFloorII(int number) {
        if (number == 0 || number == 1)
        {
            return 1;
        }
        int res = 1;
        for (int i = 2; i <= number; i++)
        {
            res = (res << 1);
        }
        return res;
    }

};