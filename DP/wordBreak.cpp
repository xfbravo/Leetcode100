#include <string>
#include <vector>
#include <unordered_set>
class Solution
{
public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        int sSize = s.size();
        std::unordered_set<std::string, bool> set;
        int dictSize = wordDict.size();
        //用set来记录单词，便于访问单词是否存在
        for(std::string word:wordDict){
            set.insert(word);
        }
        std::vector<bool> dp(sSize + 1);
        dp[0] = true;
        for (int i = 1; i < sSize;i++){
            for (int j = 0; j < i;j++){
                //当前读取到第i个字符，对于[0,i-1]的字符中
                //对于第j个字符，先查看前j个字母是否可以由字典中的词组成
                //再看后面i-j个字符组成的单词是否在字典中
                if(dp[j]&&set.find(s.substr(j+1,i-j))!=set.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[sSize];
    }
};