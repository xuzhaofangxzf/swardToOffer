/*
    输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
    例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    //方法1:暴力法,全排列,然后再
    string PrintMinNumber(vector<int> numbers) {
        string ret(numbers.size(), '9');
        permulation(numbers, 0, ret);
        return ret;
    }

private:
    void permulation(vector<int>& numbers, int pos, string &ret)
    {
        if ((pos + 1) == numbers.size())
        {
            string tmp = "";
            for (const int n : numbers)
            {
                tmp += to_string(n);
            }
            ret = min(ret, tmp);
            return;
        }
        for (int i = pos; i < numbers.size(); i++)
        {
            swap(numbers[i], numbers[pos]);
            permulation(numbers, pos + 1, ret);
            swap(numbers[i], numbers[pos]);
        }
    }

    //方法2: 自定义排序规则,将数组中的数据转化成字符串,然后进行排序, 自定义a + b > b + a
    string PrintMinNumber(vector<int> numbers)
    {
        vector<string> str;
        for (const int num : numbers)
        {
            str.push_back(to_string(num));
        }
        sort(str.begin(), str.end(), [](string a, string b){return a + b < b + a;});
        string ret = "";
        for (string strtmp: str)
        {
            ret += strtmp;
        }

        return ret;
    }
    
};
//库函数全排列
#if 0
class Solution {
public:
    string PrintMinNumber(vector<int> nums) {
        vector<string> str;
        for (int val : nums) {
            str.push_back(to_string(val));
        }  
        sort(str.begin(), str.end());
        string ret(nums.size(), '9');
        do {
            string tmp = "";
            for (string val : str)
                tmp += val;
            ret = min(ret, tmp);
        } while (next_permutation(str.begin(), str.end()));
        return ret;
    }
};

#endif 


#if 0
显然方法一出现了太多无关的排列，我们需要一个最小的数，细想一下可知，如果有两个字符串a,b，
如果a + b < b + a, 显然我们希望a排在b的前面，因为a排在前面可以使结果更小。于是我们就自定义排序规则，使得vector中字符串都满足如上规则，那么最后的结果肯定是最小的。
算法步骤：

将vector<int> 转化为vector<string>
自定义上述排序规则
整合结果
对于第二步的排序规则，实现上，可以用仿函数，lambda表达式，函数指针，针对本题的实现分别如下：

仿函数

struct Com {
    bool operator() (string a, string b) {
     return a + b < b + a;
    }
};
sort(str.begin(), str.end(), Com()); // Com()为临时对象
lambda表达式

// 1. 匿名lambda表达式
sort(str.begin(), str.end(), [](string a, string b) {
     return a + b < b + a;
});
// 2.具名lambda表达式
auto lam = [](string a, string b) {
     return a + b < b + a;
 };
sort(str.begin(), str.end(), lam);;
函数指针

bool static com(string a, string b) {
    return a + b < b + a;
}
//加static的原因：类成员函数有隐藏的this指针,static 可以去this指针
sort(str.begin(), str.end(), com);
最后的代码为：

class Solution {
public:
    string PrintMinNumber(vector<int> nums) {
        vector<string> str;
        for (int val : nums) str.push_back(to_string(val));
        sort(str.begin(), str.end(), [](string a, string b) {
            return a + b < b + a;
        });
        string ret = "";
        for (string s : str) ret += s;
        return ret;
    }
};
时间复杂度：O(NlogN), 采用了排序
空间复杂度：O(N)
#endif