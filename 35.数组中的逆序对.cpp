/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007


输入描述:
题目保证输入的数组中没有的相同的数字

数据范围：

	对于%50的数据,size<=10^4

	对于%75的数据,size<=10^5

	对于%100的数据,size<=2*10^5

示例1
输入
1,2,3,4,5,6,7,0
输出
7
*/

class Solution {
private:
    const int kmod = 1000000007;
public:
    int InversePairs(vector<int> data) {
        int ret = 0;
        split(data, 0, data.size() - 1, ret);
        return ret;
    }

private:
    void split(vector<int> &data, int l, int r, int& ret)
    {
        if (l >= r) return;
        int mid = l + ((r - l) >> 1);
        split(data, l, mid, ret);
        split(data, mid + 1, r, ret);
        MergeSort(data, l, mid, r, ret);
    }
    void MergeSort(vector<int> &data, int l, int mid, int r, int& ret)
    {
        //if (l >= r) return;
        vector<int> tmp(r - l + 1);
        int i = l, j = mid + 1, k = 0;
        while (i <= mid && j <= r)
        {
            if (data[i] > data[j]) //左边的大
            {
                ret += (mid - i + 1); //左半区间i右边的数字都比右半区间的大，都是逆序
                ret %= kmod;
                tmp[k++] = data[j++];
            }
            else
            {
                tmp[k++] = data[i++];
            }
        }
        while (i <= mid)
        {
            tmp[k++] = data[i++];
        }
        while (j <= r)
        {
            tmp[k++] = data[j++];
        }
        k = 0, i = l;
        while(i <= r)
        {
            data[i++] = tmp[k++];
        }
    }
};



#if 0

class Solution {
private:
    const int kmod = 1000000007;
public:
    int InversePairs(vector<int> data) {
        int ret = 0;
        merge_sort__(data, 0, data.size() - 1, ret);
        return ret;
    }
 
 
    void merge_sort__(vector<int> &arr, int l, int r, int &ret) {
        if (l >= r) {
            return;
        }
 
        int mid = l + ((r - l) >> 1);
        merge_sort__(arr, l, mid, ret);
        merge_sort__(arr, mid + 1, r, ret);
        merge__(arr, l, mid, r, ret);
    }
 
    void merge__(vector<int> &arr, int l, int mid, int r, int &ret) {
        vector<int> tmp(r - l + 1);
        int i = l, j = mid + 1, k = 0;
 
        while (i <= mid && j <= r) {
            if (arr[i] > arr[j]) {
                tmp[k++] = arr[j++];
                // 奥妙之处
                ret += (mid - i + 1);
                ret %= kmod;
            }
            else {
                tmp[k++] = arr[i++];
            }
        }
 
        while (i <= mid) {
            tmp[k++] = arr[i++];
        }
        while (j <= r) {
            tmp[k++] = arr[j++];
        }
 
        for (k = 0, i = l; i <= r; ++i, ++k) {
            arr[i] = tmp[k];
        }
    }
};
刚才提到在函数内部开辟额外空间的做法很不好。因为这样会涉及到频繁的构建 vector 和析构vector，所以比较好的做法是：直接在最外层开辟一个足够大的数组，然后传引用到函数。

class Solution {
private:
    const int kmod = 1000000007;
public:
    int InversePairs(vector<int> data) {
        int ret = 0;
        // 在最外层开辟数组
        vector<int> tmp(data.size());
        merge_sort__(data, tmp, 0, data.size() - 1, ret);
        return ret;
    }
 
    void merge_sort__(vector<int> &arr, vector<int> &tmp, int l, int r, int &ret) {
        if (l >= r) {
            return;
        }
 
        int mid = l + ((r - l) >> 1);
        merge_sort__(arr, tmp, l, mid, ret);
        merge_sort__(arr, tmp, mid + 1, r, ret);
        merge__(arr, tmp, l, mid, r, ret);
    }
 
    void merge__(vector<int> &arr, vector<int> &tmp, int l, int mid, int r, int &ret) {
        int i = l, j = mid + 1, k = 0;
 
        while (i <= mid && j <= r) {
            if (arr[i] > arr[j]) {
                tmp[k++] = arr[j++];
                ret += (mid - i + 1);
                ret %= kmod;
            }
            else {
                tmp[k++] = arr[i++];
            }
        }
 
        while (i <= mid) {
            tmp[k++] = arr[i++];
        }
        while (j <= r) {
            tmp[k++] = arr[j++];
        }
 
        for (k = 0, i = l; i <= r; ++i, ++k) {
            arr[i] = tmp[k];
        }
    }
 
};
#endif