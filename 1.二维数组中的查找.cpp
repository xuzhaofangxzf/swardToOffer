/*
    在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/
#include <vector>
using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        for (int i = 0; i < array.size(); i++)
        {
            if(binarysearch(array[i], 0, array[0].size() - 1, target)){
                return true;
            }
        }
        return false;

    }
private:
    bool binarysearch(vector<int> &array, int left, int right, int target)
    {
        if (left > right)
        {
            return false;
        }
        int mid = left + (right - left) / 2;
        if(array[mid] == target)
        {
            return true;
        }
        else if(array[mid] > target)
        {
            return binarysearch(array, left, mid - 1, target);
        }
        else
        {
            return binarysearch(array, mid + 1, right, target);
        }
        return false;
        
    }

public:
/*
    以右上角为起点，判断假如array[r][c] > target，则向左移动一列，如果array[r][c] < target，向下移动一行
    事件复杂度O(m+n)
*/
    bool Find(int target, vector<vector<int> >array){
        if (array.size() == 0)
        {
            return false;
        }
        int m = array.size();

        int n = array[0].size();
        if (n == 0)
        {
            return false;
        }
        int r = 0, c = n - 1;
        while (r < m && c >= 0)
        {
            if (array[r][c] > target)
            {
                c--
            }
            else if(array[r][c] < target)
            {
                r++;
            }
            else
            {
                return true;
            }
            
        }
        return false;

    }
};