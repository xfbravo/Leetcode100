#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // Initialize with sum 0 occurring once
        int sum = 0;
        for (int i = 0;i< nums.size();i++){
            sum += nums[i];
            if(prefixSumCount.find(sum-k) != prefixSumCount.end()){
                count += prefixSumCount[sum-k];
            }
            prefixSumCount[sum]++;
        }

        return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int result = s.subarraySum(nums, k);
    cout << result << endl;
    return 0;
}