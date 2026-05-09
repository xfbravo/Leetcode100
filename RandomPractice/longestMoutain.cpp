/*
LeetCode 845. Longest Mountain in Array
*/
#include <vector>

class Solution
{
public:
    int longestMountain(std::vector<int> &arr)
    {
        int n = arr.size();
        if(n<3){
            return 0;
        }
        int longest = 0;
        int left = 0;
        int right = 0;
        while(right<n-1){
            // 先找到上升的部分
            while(right<n-1 && arr[right+1]>arr[right]){
                right++;
            }
            // 再找到下降的部分
            int peak = right;
            while(right<n-1 && arr[right+1]<arr[right]){
                right++;
            }
            // 如果存在上升和下降的部分，更新最长山脉长度
            if(peak>left && right>peak){
                longest = std::max(longest, right-left+1);
            }
            // 如果遇到相同高度，将 left 移动到 right 的位置，继续寻找下一座山
            while(right<n-1 && arr[right+1]==arr[right]){
                right++;
            }

            // 将 left 移动到 right 的位置，继续寻找下一座山
            left = right;
        }
        return longest>=3?longest:0;
    }
};
int main()
{
    Solution s;
    std::vector<int> arr = {2, 1, 4, 7, 3, 2, 5};
    int result = s.longestMountain(arr);
    return 0;
}