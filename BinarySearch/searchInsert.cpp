#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int size = nums.size();
        int left = 0;
        int right = size;
        int mid = left + (right - left) / 2;

        while (right > left)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
            {
                right = mid;
                continue;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
                continue;
            }
        }
        return left;
    }
};