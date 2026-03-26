#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    // 从左向右，维护left和right指针，表示当前的字符串
    // 如果当前字符串是回文串，那么right(或者left，left<right)继续向后移动（不将该回文串加入curr），然后回溯。将该字符串加入curr，left=right+1，right=right+1,（将该回文串加入curr）
    // 如果当前字符串不是回文串，right继续向后移动，或者left向后移动（left<right）
    bool isPalindrome(const string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    };
    void backtrack(const string &s, vector<vector<string>> &result, vector<string> &curr, int left, int right, int size)
    { // 如果到末尾了
        if (right == size - 1)
        {
            // 如果是回文串，那么加入结果
            if (isPalindrome(s, left, right))
            {
                curr.push_back(s.substr(left, right - left + 1));
                result.push_back(curr);
                curr.pop_back();
                return;
            }
            else
            {
                return;
            }
        }
        // 如果没到结尾
        // 如果是回文串，那么将该回文串加入curr中
        if (isPalindrome(s, left, right))
        {
            curr.push_back(s.substr(left, right - left + 1));
            backtrack(s, result, curr, right + 1, right + 1, size);
            curr.pop_back();
        }
        // 继续向后读
        backtrack(s, result, curr, left, right + 1, size);
    };
    vector<vector<string>> partition(string s)
    {
        int size = s.size();
        vector<vector<string>> result;
        vector<string> curr;
        backtrack(s, result, curr, 0, 0, size);
        return result;
    }
};