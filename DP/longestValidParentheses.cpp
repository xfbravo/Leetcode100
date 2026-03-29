#include <string>
#include <vector>
#include <stack>
using std::string;
using std::vector;
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        if(n<2)
            return 0;
        // dp[i]表示以s[i]结尾的最长有效括号
        vector<int> dp(n, 0);
        int maxLength = 0;
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '(')
            {
                dp[i] = 0;
                continue;
            }
            else
            {
                // s[i] == ')'
                if (s[i - 1] == '(')
                {
                    dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
                    maxLength = std::max(dp[i], maxLength);
                }
                else if (s[i - 1] == ')')
                {
                    int L = dp[i - 1];
                    int p = i - L - 1;
                    // 如果p>=0,那么s[p]一定是'('
                    if (p >= 0&&s[p] == '(')
                    {
                        dp[i] = p - 1 >= 0 ? dp[i - 1] + 2 + dp[p - 1] : dp[i - 1] + 2;
                        maxLength = std::max(dp[i], maxLength);
                    }
                }
            }
        }
        return maxLength;
    }
};

int main()
{
    Solution s;
    string str = ")()())";
    int a = s.longestValidParentheses(str);
    return 0;
}