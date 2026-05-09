#include <vector>
class Solution
{
public:
    int minSubArrayLen(int target, std::vector<int> &nums)
    {
        int left=0, right=0;
        int n = nums.size();
        int sum = 0;
        int minLen = n+1;
        for(right=0; right<n; right++){
            sum += nums[right];
            if(sum >= target){
                minLen = std::min(minLen, right-left+1);
                while(sum >= target){
                    sum -= nums[left];
                    left++;
                    if(sum >= target){
                        minLen = std::min(minLen, right-left+1);
                    }
                }   
            }
        }
        return minLen == n+1 ? 0 : minLen;
    }
};