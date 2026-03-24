#include <vector>
using namespace std;

class Solution
{
public:
    void backtrack(vector<int> &nums, vector<int> &currentNums, vector<vector<int>> &result, int t, int n)
    {
        if (t == n)
        {
            result.push_back(currentNums);
        }
        else
        {
            currentNums.push_back(nums[t]);
            backtrack(nums, currentNums, result, t + 1, n);
            currentNums.pop_back();
            backtrack(nums, currentNums, result, t + 1, n);
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> currentNum;
        backtrack(nums, currentNum,result, 0, n);
        return result;
    }
};