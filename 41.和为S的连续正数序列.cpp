/*
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
*/

class Solution {
public:

    //方法1：直接暴力解决
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        for (int i = 1; i <= sum / 2; i++)
        {
            int tmp = 0;
            for (int j = i; j < sum; j++)
            {
                tmp += j;
                if (tmp == sum)
                {
                    vector<int> tempv;
                    for (int k = i; k <= j; k++)
                    {
                        tempv.push_back(k);
                    }
                    res.push_back(tempv);
                }
                else if(tmp > sum)
                {
                    break;
                }
            }
        }
        return res;
    }
    //方法2：滑动窗口
    vector<vector<int> > FindContinuousSequence(int sum)
    {
        vector<vector<int> > res;
        int i = 1, j = 1;
        int sumtmp = 0;
        while (i <= sum / 2)
        {
            if (sumtmp < sum)
            {
                sumtmp += j;
                j++;
            }
            else if (sumtmp == sum)
            {
                vector<int> tempv;
                for (int k = i; k < j; k++)
                {
                    tempv.push_back(k);
                }
                res.push_back(tempv);
                sumtmp -= i;
                i++;
            }
            else // (sumtmp > sum) //窗口缩小
            {
                sumtmp -= i;
                i++;
            }
        }
        return res;
    }

};