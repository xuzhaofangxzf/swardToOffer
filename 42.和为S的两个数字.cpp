/*
    输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
    输出描述:
    对应每个测试案例，输出两个数，小的先输出。
*/

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if (array.size() < 2) return vector<int>(0);
        vector<int> res;
        for (int i = 0; i < array.size();)
        {
            for (int j = i + 1; j < array.size();)
            {
                if (array[i] + array[j] == sum)
                {
                    res.push_back(array[i]);
                    res.push_back(array[j]);
                    return res;
                }
                else if (array[i] + array[j] > sum)
                {
                    j--;
                    i++;
                }
                else // 小于
                {
                    j++;
                }
   
            }
        }
        return res;
    }
};