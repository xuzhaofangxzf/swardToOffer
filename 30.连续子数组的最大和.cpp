/*
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    //动态规划
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int> dpres(array.size(), 0); //dp保存的各个状态,res[i]表示以i为结尾的最大子序列和
        dpres[0] = array[0];
        for (int i = 1; i < array.size(); i++)
        {
            dpres[i] = max(dpres[i - 1] + array[i], array[i]);
        }
        int max = dpres[0];
        for (int i = 0; i < dpres.size(); i++)
        {
            if (dpres[i] > max) max = dpres[i];
        }
        return max;
        
    }
    //方法2: 设定一个初始的和为0,分别与各个元素相加,如果与元素相加,和<0
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        int sum = 0;
        int res = array[0];
        for (int i = 0; i < array.size(); i++)
        {
            if (sum + array[i] < 0)
            {
                sum = 0;
            }
            else
            {
                sum += array[i];
            }
            res = max(res, sum);
            
        }
        if (sum != 0) //
        {
            return res;
        }
        return *max_element(array.begin(), array.end());
    }
    //方法3: 优化
    //1.dp[i]表示以i为结尾的最大子序列的和,将结果加到对应的array[i]中,节省了空间
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        int maxVal = array[0];
        for (int i = 1; i < array.size(); i++)
        {
            array[i] += (array[i - 1] > 0) ? array[i - 1] : 0; //如果前一个最大子序列的和为正,则加进去.
            maxVal = max(maxVal, array[i]);
        }
        return maxVal;
    }

};


#if 0
思想很简单，就是对下标为i的元素array[i]，先试探的加上array[i], 如果和为负数，显然，以i结尾的元素对整个结果不作贡献。
具体过程：

初始化：维护一个变量tmp = 0
如果tmp+array[i] < 0, 说明以i结尾的不作贡献，重新赋值tmp = 0
否则更新tmp = tmp + array[i]
最后判断tmp是否等于0， 如果等于0， 说明数组都是负数，选取一个最大值为答案。

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int ret = array[0];
        int tmp = 0;
        for (const int k : array) {
            if (tmp + k < 0) {
                tmp = 0;
            }
            else {
                tmp += k;
            }
            ret = max(ret, tmp);
        }
        if (tmp != 0)
            return ret;
        return *max_element(array.begin(), array.end());
    }
};


典型的动态规划。dp[n]代表以当前元素为截止点的连续子序列的最大和，
如果dp[n-1]>0，dp[n]=dp[n]+dp[n-1]，因为当前数字加上一个正数一定会变大；
如果dp[n-1]<0，dp[n]不变，因为当前数字加上一个负数一定会变小。使用一个变量max记录最大的dp值返回即可。

public int FindGreatestSumOfSubArray(int[] array) {
    int max = array[0];
    for (int i = 1; i < array.length; i++) {
        array[i] += array[i - 1] > 0 ? array[i - 1] : 0;
        max = Math.max(max, array[i]);
    }
    return max;
}
#endif