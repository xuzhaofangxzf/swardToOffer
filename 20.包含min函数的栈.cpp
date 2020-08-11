//定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    void push(int value) {
        s1.push(value);
        if (s2.empty())
        {
            s2.push(value);
        }
        if (s2.top() >= value) //相等也放进来,因为后面弹出的时候,如果只有一个,就没有了当前的最小值了.
        {
            s2.push(value);
        }
    }
    void pop() {
        if(s1.top() == s2.top())
        {
            s2.pop();
        }
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
private:
    stack<int> s1; //s1放置元素
    stack<int> s2; //s2栈顶保存最小的元素
};