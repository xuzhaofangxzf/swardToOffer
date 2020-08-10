
/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        vector<int> dp(number + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= number; i++)
        {
            dp[i] = dp[i - 1] + dp[i -2];
        }
        return dp[number];
    }
};