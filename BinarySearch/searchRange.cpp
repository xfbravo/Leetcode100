#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> result(2, -1);
        int size = nums.size();
        if (size == 0){
            return result;
        }
            int left = 0;
        int right = nums.size();
        int mid = left + (right - left) / 2;
        while (right > left)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                break;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if (nums[mid] != target)
        {
            return result;
        }
        left = mid - 1;
        right = mid + 1;
        while (left >= 0)
        {
            if (nums[left] != target)
            {
                break;
            }
            left--;
        }
        left++;
        while (right < size)
        {
            if (nums[right] != target)
            {
                break;
            }
            right++;
        }
        right--;
        result[0] = left;
        result[1] = right;
        return result;
    }
};