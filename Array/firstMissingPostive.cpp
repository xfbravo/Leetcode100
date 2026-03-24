#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int size = nums.size();
        int result = size + 1;
        bool hasOne = false;
        // 查看1是否在数组中，如果不在，那么1就是第一个缺失的正数
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == 1)
            {
                hasOne = true;
            }
            // 不在1~size范围内的数都不可能是第一个缺失的正数了，把它们都改成1，这样就不会影响后续的判断了
            if (nums[i] <= 0 || nums[i] > size)
            {
                nums[i] = 1;
            }
        }
        // 如果数组中没有1，那么之前的循环就把result改成了2了，这时就说明1是第一个缺失的正数了，直接返回1
        if (!hasOne)
        {
            return 1;
        }
        // 把数组中的数当成索引，把对应位置的数改成负数，表示这个索引对应的数在数组中出现过了
        for (int i = 0; i < size; i++)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0)
            {
                nums[index] = -nums[index];
            }
        }
        // 从1开始，找到第一个对应位置的数是正数的索引，这个索引就是第一个缺失的正数
        for (int i = 0; i < size; i++)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }
        return size + 1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 4, -1, 1};
    int result = s.firstMissingPositive(nums);
    cout << result << endl;
    return 0;
}