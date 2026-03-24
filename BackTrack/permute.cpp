#include <vector>
using namespace std;

class Solution
{
public:
    void backtrack(vector<int> &nums, vector<vector<int>> &result, int t,int n){
        if(t==n){
            result.push_back(nums);
            return;
        }
        else{
            for (int i = t; i < n;i++){
                swap(nums[t], nums[i]);
                backtrack(nums, result, t + 1, n);
                swap(nums[t], nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        int n = nums.size();
        backtrack(nums,result,0,n);
        return result;
    }
};