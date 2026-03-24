#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        string result;
        int minLength=INT_MAX;
        int tCharCount = 0;//统计t中有多少种不同的字符
        unordered_map<char, int> tCount;//统计t中每个字符出现的次数
        for (char c : t)
        {
            tCount[c]++;
            if(tCount[c] == 1)
            {
                tCharCount++;
            }
        }
        unordered_map<char, int> sCount;//统计当前窗口中每个字符出现的次数
        int left = 0;//窗口的左边界
        int right = 0;//窗口的右边界
        int sSize = s.size();//s的长度
        int count = 0;//统计当前窗口中已经满足t中字符要求的字符种类数
        while(right < sSize){
            char rightChar = s[right];
            sCount[rightChar]++;
            //如果当前窗口中某个字符的出现次数和t中该字符的出现次数相等了，就说明这个字符已经满足了t中的要求，满足的字符种类数加1
            if(sCount[rightChar] == tCount[rightChar]){
                count++;
            }
            //如果左侧窗口中的字符出现次数比t中多了（或者压根就不在t中），则可以移动左窗口进一步缩小
            char leftChar = s[left];
            while(sCount[leftChar]> tCount[leftChar]&&tCount.find(leftChar) != tCount.end()){
                sCount[leftChar]--;
                left++;
                leftChar = s[left];
            }
            //如果当前窗口中已经满足了t中所有字符的要求了，就尝试缩小窗口，看看能不能找到更短的满足要求的子串
            while(count == tCharCount){
                //如果当前窗口的长度比之前找到的最短满足要求的子串还短，就更新结果
                if(right - left +1 < minLength)
                {
                    minLength = right - left +1;
                    result = s.substr(left, minLength);
                }
                leftChar = s[left];
                //当窗口左边界字符的出现次数和t中该字符的出现次数相等时，说明这个字符不满足t中的要求了，满足的字符种类数减1
                if(sCount[leftChar] == tCount[leftChar]){
                    count--;
                }
                sCount[leftChar]--;
                left++;
            }
            //从循环中结束，说明窗口此时不满足条件，窗口右边界向右移动，继续扩大窗口
            right++;
        }
        return result;
    }
};