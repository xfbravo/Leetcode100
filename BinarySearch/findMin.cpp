#include <vector>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = left + (right - left) / 2;
        while(right>left){
            mid = left + (right - left) / 2;
            //右边有序,说明最小值在左边
            if(nums[mid]<=nums[right]){
                right = mid;
            }else{//左边有序，最小值在右边
                left = mid + 1;
            }
        }
        return nums[left];
    }
};