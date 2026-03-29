#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution
{
public:
    /*
    dp[i][j]表示text1前i部分和text2前j部分的最长公共子序列的长度
    if(text1[i] == text2[j]){
        dp[i][j] = dp[i-1][j-1]+1;
    }else{
        dp[i][j] = max(
            dp[i-1][j] 
            dp[i][j-1]
        )
    }
    )
    */
    int longestCommonSubsequence(string text1, string text2)
    {
        int l1 = text1.size();
        int l2 = text2.size();
        if(!l1||!l2){
            return 0;
        }
        int maxLength = 0;
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[l1][l2];
    }
};