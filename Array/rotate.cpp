#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int size = nums.size();
        k = k % size; //如果k大于数组长度了，那么旋转k次和旋转k%size次的结果是一样的

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};