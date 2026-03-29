#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution
{
public:
    // dp[i][j]表示从i..j是否是回文串，j-i+1就是回文串的长度
    // dp[i][j] = dp[i+1][j-1] &&s[i] == s[j] ,j-i+1>=3
    // dp[i][j] = s[i]==s[j], j-i+1==2 => j=i+1
    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n < 2)
            return s;
        int length = 1;
        int start = 0;
        string longest = s.substr(0, 1);
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        //长度为1的串是回文串
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }
        //len表示字符串的长度
        for (int len = 2; len <= n; len++)
        {
            //i表示字符串的起始位置
            for (int i = 0; i <= n - len; i++)
            {
                //计算字符串的结束位置
                int j = i + len - 1;
                //如果长度==2，那么只需要表两个字符是否相等
                if (len == 2)
                {
                    dp[i][j] = s[i] == s[j];
                    if (dp[i][j] && len > length)
                    {
                        length = len;
                        start = i;
                    }
                }
                //如果长度>2，那么要确保两头字符串相等，而且中间的子串也是回文串
                else if (len > 2)
                {
                    dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                    if (dp[i][j] && len > length)
                    {
                        length = len;
                        start = i;
                    }
                }
            }
        }
        longest = s.substr(start, length);
        return longest;
    }
};
int main()
{
    Solution s;
    string str = "aaaa";
    string ans = s.longestPalindrome(str);
    return 0;
}