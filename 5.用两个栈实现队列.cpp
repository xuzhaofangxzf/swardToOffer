//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
#include <iostream>
#include <stack>
using namespace std;
class Solution
{
public:
    //压栈，直接压栈到stack1中
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int res;
        //假如stack2不为空，则可以直接弹出stack2栈顶元素，假如stack2为空，则需要将所有的stack1的元素压入到stack2中，然后弹出stack栈顶元素。
        if (!stack2.empty())
        {
            res = stack2.top();
            stack2.pop();
            return res;
        }
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        res = stack2.top();
        stack2.pop();
        return res;

    }

private:
    stack<int> stack1;
    stack<int> stack2;
};