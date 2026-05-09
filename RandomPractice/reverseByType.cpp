/*
LeetCode 3823. Reverse String by Type
*/
#include <string>
class Solution
{
public:
    std::string reverseByType(std::string s)
    {
        int n = s.size();
        // 先反转字母
        int left = 0;
        int right = n - 1;
        while(right>left){
            // 找到左边的字母
            while(right>left && !isalpha(s[left])){
                left++;
            }
            // 找到右边的字母
            while(right>left && !isalpha(s[right])){
                right--;
            }
            // 如果左右两边不是同一个位置，交换它们
            if(right>left){
                std::swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        // 再反转特殊字符
        left = 0;
        right = n - 1;
        while(right>left){
            // 找到左边的特殊字符
            while(right>left && isalpha(s[left])){
                left++;
            }
            // 找到右边的特殊字符
            while(right>left && isalpha(s[right])){
                right--;
            }
            // 如果左右两边不是同一个位置，交换它们
            if(right>left){
                std::swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};