#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        //priority_queue<int, vector<int>, greater<int> > q;
        if (k == 0) return vector<int>(0);
        priority_queue<int> q; //默认大顶堆
        for (int i = 0; i < input.size(); i++)
        {
            if (q.size() < k)
            {
                q.push(input[i]);
            }
            else if(q.size() == k)
            {
                if (q.top() > input[i])
                {
                    q.pop();
                    q.push(input[i]);
                }
            }
        }

        vector<int> res;
        while (!q.empty())
        {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k > input.size() || k == 0) return vector<int>(0);
        priority_queue<int> q; //默认大顶堆
        for (int i = 0; i < k; i++)
        {
            q.push(input[i]);
        }
        for (int i = k; i < input.size(); i++)
        {
            if (q.top() > input[i])
            {
                q.pop();
                q.push(input[i]);
            }
        }


        vector<int> res(k, 0);
        for (int i = 0; i < k; i++)
        {
            res[i] = q.top();
            q.pop();
        }
        return res;
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) return vector<int>(0);
        priority_queue<int> q; //默认大顶堆
        for (int i = 0; i < arr.size(); i++)
        {
            if (q.size() < k)
            {
                q.push(arr[i]);
            }
            else if(q.size() == k)
            {
                if (q.top() > arr[i])
                {
                    q.pop();
                    q.push(arr[i]);
                }
            }
        }

        vector<int> res;
        while (!q.empty())
        {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};