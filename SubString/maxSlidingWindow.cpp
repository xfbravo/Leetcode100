#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <deque>
using namespace std;
// class Solution
// {
// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k)
//     {
//         vector<int> result;
//         int n = nums.size();
//         int max = 0;
//         for (int i = 0; i < n - k + 1;i++){
//             if(i == 0){
//                 for (int j = 0; j < k;j++){
//                     if(nums[j] > max){
//                         max = nums[j];
//                     }
//                 }
//             }else{
//                 if(nums[i+k-1]>=max){
//                     max = nums[i+k-1];
//                 }else{
//                     if(nums[i-1] == max){
//                         max = nums[i];
//                         for (int j = i+1; j < i+k;j++){
//                             if(nums[j] > max){
//                                 max = nums[j];
//                             }
//                         }
//                     }
//                 }
//             }
//             result.push_back(max);
//         }
//         return result;
//     }
// };

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        int n = nums.size();
        deque<int> dq;
        for (int i = 0; i < n; i++){
            //只要当前元素比队列尾部元素大，就把队列尾部元素弹出，直到当前元素不比队列尾部元素大或者队列为空
            //这样能确保队列中的元素是单调递减的，队列头部元素就是当前窗口的最大值
            while(!dq.empty()  && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            //把当前元素的索引加入队列
            dq.push_back(i);

            //如果队列的头部元素的索引已经不在当前窗口范围内了，就把它弹出
            if(dq.front() == i-k){
                dq.pop_front();
            }

            //从第k-1个元素开始，开始将队列头部元素（窗口最大值）加入结果
            if(i >= k-1){
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};