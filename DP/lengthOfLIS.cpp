#include <vector>

class Solution
{
public:
    // 暴力解法
    int lengthOfLIS(std::vector<int> &nums)
    {
        int n = nums.size();
        std::vector<int> dp(n + 1, 1);
        int max = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                    max = std::max(max, dp[i]);
                }
            }
        }
        return max;
    }

    // 贪心+二分查找
    int binarySearch(const std::vector<int> &dp, int len, int num)
    {
        int left = 1;
        int right = len;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (dp[mid] < num)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
    int lengthOfLIS2(std::vector<int> &nums)
    {
        int n = nums.size();
        std::vector<int> dp;
        int len = 1;
        dp.push_back(0);
        dp.push_back(nums[0]);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > dp[len])
            {
                len++;
                dp.push_back(nums[i]);
            }
            else
            {
                int index = binarySearch(dp, len,nums[i]);
                dp[index] = nums[i];
            }
        }
        return len;
    }
};