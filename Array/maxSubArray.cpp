#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int size = nums.size();
        int maxSum = nums[0];
        int currentSum = nums[0];
        for (int i = 1; i < size;i++){
            //如果之前元素之和小于0，那么加上它们只会让和更小，直接从当前元素开始重新计算和
            if(currentSum < 0){
                currentSum = nums[i];
            }
            //否则就把当前元素加到之前元素之和上
            else{
                currentSum += nums[i];
            }
            //更新最大和
            if(currentSum > maxSum){
                maxSum = currentSum;
            }
        }
        return maxSum;
    }
};