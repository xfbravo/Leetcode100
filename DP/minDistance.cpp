#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution
{
public:
    /*
    dp[i][j]表示word1的前i个字母的子串转化为word2的前j个字母的子串最少需要多少步
    if(word1[i]== word2[j]) dp[i][j] = dp[i-1][j-1];
    else dp[i][j] = min(
        dp[i][j-1]+1    ,在word1尾部插入和word2尾部的相同字母，然后消除  dp[i+1][j]+1->dp[i][j-1]+1
        dp[i-1][j]+1    ,删除word1尾部的元素,继续用word1剩余字母继续比较 dp[i-1][j]+1
        dp[i-1][j-1]+1  ,替换word1尾部字母为word2尾部的字母，然后消除    dp[i]dp[j]+1->dp[i-1][j-1]+1
    )
    */
    int minDistance(string word1, string word2)
    {
        int l1 = word1.length();
        int l2 = word2.length();
        if (!l1 && !l2)
        {
            return std::max(l1, l2);
        }
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        //初始化dp
        for (int i = 1; i <= l1; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 1; j <= l2; j++)
        {
            dp[0][j] = j;
        }
        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = std::min(dp[i][j - 1], std::min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                }
            }
        }
        return dp[l1][l2];
    }
};