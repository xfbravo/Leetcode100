#include <vector>
#include <algorithm>
class Solution
{
public:
    bool canJump(std::vector<int> &nums)
    {
        int n = nums.size();
        int farthest = 0;
        int i = 0;
        while(i<=farthest){
            farthest = std::max(farthest, i + nums[i]);
            if(farthest>=n-1){
                return true;
            }
            i++;
        }
        return false;
    }
};