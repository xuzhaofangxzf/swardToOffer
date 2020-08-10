
///输入一个整数，输出该数32位二进制表示中1的个数。其中负数用补码表示。

#include <iostream>
using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
         int cnt = 0;
         while (n != 0)
         {
             n = n & (n - 1); //去掉最后一位的1
             cnt++;
         }
         return cnt;
     }
};