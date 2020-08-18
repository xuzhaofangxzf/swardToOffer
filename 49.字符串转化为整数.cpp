//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
/*
    输入描述:
    输入一个字符串,包括数字字母符号,可以为空
    输出描述:
    如果是合法的数值表达则返回该数字，否则返回0
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        int len = str.size();
        int i = 0;
        int flag = 1; //正负标记
        int res = 0; //结果
        while (i < len && str.at(i) == ' ')
        {
            i++;
        }
        if (str[i] == '+')
        {
            flag = 1;
            i++;
        }
        else if(str[i] == '-')
        {
            flag = -1;
            i++;
        }
        else
        {
            flag = 1;
        }

        while (i < len)
        {
            
            if (str[i] >= '0' && str[i] <= '9')
            {
                int data = str[i] - '0';
                if (flag > 0)
                {

                    if (res > INT64_MAX / 10)
                    {
                        return INT64_MAX;
                    }
                    res *= 10;
                    if (res > INT64_MAX - data)
                    {
                        return INT64_MAX;
                    }
                    res += data;
                }
                else
                {
                    if (res < INT64_MIN / 10)
                    {
                        return INT64_MIN;
                    }
                    res *= 10;
                    if (res < INT64_MIN + data)
                    {
                        return INT64_MIN;
                    }
                    res -= data;
                }
                i++;
            }
            else
            {
                return 0;
            }
            
        }
        return res;
    }
};