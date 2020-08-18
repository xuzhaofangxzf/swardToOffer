/*
把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。
求按从小到大的顺序的第N个丑数。
*/
#include <iostream>
using namespace std;



class Solution {
public:
    int GetUglyNumber_Solution(int index) {

        int base2 = 0, base3 = 0, base5 = 0;
        int* uglyNumbers = new int[index];
        uglyNumbers[0] = 1;
        for (int i = 1; i < index; i++)
        {
            int n2 = uglyNumbers[base2] * 2;
            int n3 = uglyNumbers[base3] * 3;
            int n5 = uglyNumbers[base5] * 5;
            uglyNumbers[i] = min(min(n2, n3), n5); //取最小值
            if(uglyNumbers[i] == n2) base2++;
            if(uglyNumers[i] == n3) base3++;
            if(uglyNumers[i] == n5) base5++;

        }

        return uglyNumbers[index - 1];
        
    }
};