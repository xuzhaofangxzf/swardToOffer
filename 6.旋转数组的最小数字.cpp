/*
    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
    输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
    例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
    NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //方法1: 二分法
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0)
        {
            return 0;
        }
        int start = 0;
        int end = rotateArray.size() -1;
        while (start < end)
        {
            if (rotateArray[start] < rotateArray[end])
            {
                return rotateArray[start];
            }
            int mid = start + ((end - start) >> 1);
            //与右端点比较,如果大于右端点,说明左边的值都比右边的大,最小值在右边
            if (rotateArray[mid] > rotateArray[end])
            {
                start = mid + 1;
            }
            //如果小于右端点,说明最小值在左边,mid也有可能是最小值
            else if(rotateArray[mid] < rotateArray[end])
            {
                end = mid;
            }
            //如果相等,假如1,1,1,0,1,或者1,1,0,1,1, 两边都有可能是,此时将右边界向左移动,慢慢缩小区间.
            else
            {
                end--;
            }
        }
        return rotateArray[start];
    }
    //方法2: 递归二分
    int minNumberInRotateArray(vector<int> rotateArray){
        if (rotateArray.size() == 0)
        {
            return 0;
        }
        return getMin(rotateArray, 0, rotateArray.size() - 1);
    }
private:
    int getMin(vector<int> rotateArray, int left, int right)
    {
        if (left == right)
        {
            return rotateArray[left];
        }
        int mid = left + ((right - left) >> 1);
        if (rotateArray[mid] > rotateArray[right])
        {
            return getMin(rotateArray, mid + 1, right);
        }
        if (rotateArray[mid] < rotateArray[right])
        {
            return getMin(rotateArray, left, mid);
        }
        if (rotateArray[mid] == rotateArray[right])
        {
            return getMin(rotateArray, left, right - 1);
        }
        
    }
};
