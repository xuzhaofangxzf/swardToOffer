//统计一个数字在升序数组中出现的次数。
class Solution {
public:
    //二分，先找到对应的位置，然后左右扩散
    int GetNumberOfK(vector<int> data ,int k) {
        if (data.size() == 0 ) return 0;
        int ret = 0;
        int index = BinarySearch(data, k, 0, data.size() - 1);
        if (index == -1) return 0;
        int i = index, j = index;
        while (i >=0)
        {
            if (data[i] == k)
            {
                i--;
                ret++;
            }
            else
            {
                break;
            }
        }
        while (j <= data.size() - 1)
        {
            if (data[j] == k)
            {
                j++;
                ret++;
            }
            else
            {
                break;
            }
        }
        return ret - 1;
    }
    int BinarySearch(vector<int>& data, int target, int l, int r)
    {
        if (l > r) return -1; //没找到
        int mid = l + ((r - l) >> 1);
        if (data[mid] == target)
        {
            return mid;
        }
        else if (data[mid] > target)
        {
            r =  mid - 1;
            return BinarySearch(data, target, l, r);
        }
        else
        {
            l = mid + 1;
            return BinarySearch(data, target, l, r);
        }
    }
    //方法2 C++ 标准函数
        int GetNumberOfK(vector<int> data ,int k) {
            auto l = lower_bound(data.begin(), data.end(), k);
            auto r = upper_bound(data.begin(), data.end(), k);
            return r - l;
    }
    //找上下界
    int GetNumberOfK(vector<int> data ,int k) 
    {
        int lbound = 0, rbound = 0;
        int l = 0, r = data.size();
        while (l < r)
        {
            int mid = l + ((r - l) >>1);
            if (data[mid] < k)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        lbound = l;
        l = 0, r = data.size();
        //right bound，找到第一个不是target的值
        while (l < r)
        {
            int mid = l + ((r - l) >>1);
            if(data[mid] <= k) //注意，此时如果令l = mid,最终假如 l, r相差1，且都等于target，则会陷入死循环 所以不能找右边界等于target的值。
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        rbound = l;
        return rbound - lbound;
    }
};

