/*
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。
上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 
现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。

*/


class Solution {
public:
    //方法1：先排序，然后判断0的个数，再接着判断前后两个数之间的差值，将0补位，0的个数足够就返回true，否则false

    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() != 5)
        {
            return false;
        }

        sort(numbers.begin(), numbers.end());
        //count(numbers.begin(), numbers.end(), 0); //统计0的个数
        int zeronum = 0;//0的个数
        int i = 0;
        //统计0的个数
        while (i < numbers.size() && numbers[i] == 0)
        {
            i++;
            zeronum++;
        }
    
        while (i < numbers.size())
        {
            if (i == numbers.size() - 1)
            {
                return true;
            }
            //不能相等
            if (numbers[i + 1] == numbers[i])
            {
                return false;
            }
            if (numbers[i + 1] - numbers[i] == 1)
            {
                i++;
            }
            else if ((numbers[i + 1] - numbers[i] - 1) > zeronum)
            {
                return false;
            }
            else if ((numbers[i + 1] - numbers[i] - 1) <= zeronum)
            {
                zeronum -= (numbers[i + 1] - numbers[i] - 1);
                i++;
            }
        }
        return true;
    }
    //方法2：优化，最大值与最小值的差值应该是小于5
        bool IsContinuous( vector<int> numbers ) {
        if (numbers.size() != 5)
        {
            return false;
        }
        sort(numbers.begin(), numbers.end());
        int j = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == 0)
            {
                j++;
                continue;
            }
            if ((i < numbers.size() - 1) && numbers[i + 1] == numbers[i]) return false;

        }
        return numbers.back() - numbers[j] < 5;
    }
};