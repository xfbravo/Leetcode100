#include <vector>
class Solution
{
public:
    int target = -1;
    int binarySearch(std::vector<int> &nums, int left, int right)
    {
        if (target != -1)
            return target;
        if (left >= right)
            return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == nums[mid - 1] && nums[mid] == nums[mid + 1])
        {
            target = nums[mid];
            return target;
        }
        if (mid % 2 == 0)
        {
            if (nums[mid] == nums[mid + 1])
            {
                target = binarySearch(nums, mid + 2, right);
            }
            else
            {
                target = binarySearch(nums, left, mid);
            }
        }
        else
        {
            if (nums[mid] == nums[mid - 1])
            {
                target = binarySearch(nums, mid + 1, right);
            }
            else
            {
                target = binarySearch(nums, left, mid);
            }
        }
        return target;
    }
    int singleNonDuplicate(std::vector<int> &nums)
    {
        int right = nums.size();
        if (right == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        binarySearch(nums, 0, right);
        return target;
    }
};

int main(){

    Solution s;
    std::vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int ans = s.singleNonDuplicate(nums);
}