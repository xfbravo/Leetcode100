#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty()) return 0;
        unordered_map<int, int> numMap;
        int longestStreak = 1;
        for(int num : nums) {//对哈希表初始化
            numMap[num] = 1; 
        }
        for(const auto &pair : numMap) {//遍历哈希表的元素
            int num = pair.first;
            //如果当前数字的前一个数字不在哈希表中，说明这个数字是一个新的连续序列的开始，currentStreak=1
            if (numMap.find(num - 1) == numMap.end()) {
                int currentNum = num;
                int currentStreak = 1;
                //一直查找下一个数字是否在哈希表中，如果在，长度加一，当前数字也加一
                while (numMap.find(currentNum + 1) != numMap.end()) {
                    currentNum++;
                    currentStreak++;
                }//直到下一个数字不在哈希表中
                longestStreak = max(longestStreak, currentStreak);
            }
            //如果当前数字的前一个数字在哈希表中，说明这个数字不是一个新的连续序列的开始（已经包含在某个序列中），直接跳过
        }
        return longestStreak;
    }
};