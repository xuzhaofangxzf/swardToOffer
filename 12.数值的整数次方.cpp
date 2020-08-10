/*
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

保证base和exponent不同时为0
*/
#include <iostream>
using namespace std;

class Solution {
public:
    //方法1:暴力 时间复杂度 O(n)
    double Power(double base, int exponent) {
        if (base == 0)
        {
            return 0;
        }
        if (exponent == 0)
        {
            return 1.0;
        }
        if (exponent < 0)
        {
            return 1 / Power(base, abs(exponent));
        }
        double res = 1;
        for (int i = 0; i < exponent; i++)
        {
            res *= base;
        }
        return res;
    }
    //方法2: 优化
    double Power(double base, int exponent)
    {
        if (base == 0) return 0;
        if (exponent == 0) return 1;
        if (exponent < 0) return 1 / Power(base, abs(exponent));
        double res = base;
        while (exponent > 0)
        {
            if (exponent % 2 == 0) //偶数
            {
                res *= res;
            }
            else
            {
                res *= base;
            }
            exponent >>= 1;
            
        }
        return res;
    }
    //方法3.递归法
    double Power(double base, int exponent) {
        if (base == 0) return 0;
        if (exponent == 0) return 1;
        if (exponent < 0) return 1 / Power(base, abs(exponent));
        double ret = Power(base, exponent / 2);
        if (exponent & 1 == 1) //奇数
        {
            return ret * ret * base;
        }
        else
        {
            return ret * ret;
        }
        
    }

    /*
    为了理解，假设 base=3，exponent= 5。那么 5 的二进制是：101。所以，3 的 5 次方可以写成下图的格式：
    3^5 = 3^(101)2 = 3 ^(2 ^2 + 2^0) = 3^4 * 3^1
    可以看到，对 base 进行自乘，导致 base 的指数每次都扩大 2 倍。与 exponent 的二进制相对应。
    结果值 result 初始为 1
    base 初始为 3，此时 exponent 的二进制最右位为 1，更新结果为：base * result
    exponent 右移一位。base 进行累乘，base 更新为 3 的 2 次方。由于 exponent 的二进制最右位为 0，不更新结果
    exponent 右移一位。base 进行累乘，base 更新为 3 的 4 次方。此时 exponent 的二进制最右位为 1，更新结果为：base * result
    结束
    
    */
    double Power(double base, int exponent) {
        if (base == 0) return 0;
        if (exponent == 0) return 1;
        if (exponent < 0) return 1 / Power(base, abs(exponent));
        double ret = 1.0;
        while (exponent)
        {
            if (exponent & 1) //二进制最后一位是1
            {
                ret *= base;
            }
            base *= base;
            exponent >>= 1;
        }
        return ret;

    }

};