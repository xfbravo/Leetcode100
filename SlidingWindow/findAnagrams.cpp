#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:

    vector<int> findAnagrams(string s, string p)
    {
        vector<int> result;
        unordered_map<char, int> pCount;
        int pcount;
        for (char c : p)
        {
            pCount[c]++;
        }
        pcount = pCount.size();
        unordered_map<char, int> sCount;
        int count = 0;
        int sSize = s.size();
        int pSize = p.size();
        for (int i = 0;i< sSize-pSize+1;i++){
            if(i == 0){
                for (int j = 0; j < pSize; j++)
                {
                    sCount[s[j]]++;
                    if(sCount[s[j]] == pCount[s[j]]){
                        count++;
                    }
                }
            }else{
                char leftChar = s[i-1];
                char rightChar = s[i+pSize-1];
                sCount[rightChar]++;
                if(sCount[rightChar] == pCount[rightChar]){
                    count++;
                }
                if(sCount[leftChar] == pCount[leftChar]){
                    count--;
                }
                sCount[leftChar]--;
            }
            if(count == pcount){
                result.push_back(i);
            }
        }

            return result;
    }

};

int main()
{
    Solution s;
    string str1 ="cbaebabacd";
    string str2 = "abc";
    vector<int> result = s.findAnagrams(str1, str2);
    for (int i : result)
    {
        cout << i << " ";
    }
}