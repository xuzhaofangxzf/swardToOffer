//在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
//例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        vector<bool> v(length, false);
        for (int i = 0; i < length; i++)
        {
            if (v[numbers[i]] != false)
            {
                *duplication = numbers[i];
                return true;
            }
            v[numbers[i]] = true;

        }

        return false;
    }

    /*
    方法2:

        设置一个指针i指向开头0，

        对于arr[i]进行判断，如果arr[i] == i， 说明下标为i的数据正确的放在了该位置上，让i++

        如果arr[i] != i, 说明没有正确放在位置上，那么我们就把arr[i]放在正确的位置上，也就是交换
        arr[i] 和arr[arr[i]]。交换之后，如果arr[i] ！= i, 继续交换。

        如果交换的过程中，arr[i] == arr[arr[i]]，说明遇到了重复值，返回即可。
    */

    bool duplicate(int numbers[], int length, int* duplication)
    {
        for (int i = 0; i < length; i++)
        {
            while (numbers[i] != i)
            {
                if (numbers[i] != numbers[numbers[i]])
                {

                    swap(numbers[i], numbers[numbers[i]]);
                }
                else
                {
                    *duplication = numbers[i];
                    return true;
                }
                
            }
        }
        return false;
    }
};