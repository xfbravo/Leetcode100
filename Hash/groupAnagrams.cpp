#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int size = strs.size();
        vector<vector<string>> result;
        vector<string> anagramGroup;
        for (int i = 0; i < size;i++){
            string sortedstr = strs[i];
            sort(sortedstr.begin(), sortedstr.end());
            bool found = false;
            int sizeOfGroup=anagramGroup.size();
            for (int j = 0;j<sizeOfGroup;j++){
                if(anagramGroup[j] == sortedstr){
                    result[j].push_back(strs[i]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                anagramGroup.push_back(sortedstr);
                result.push_back({strs[i]});
            }
        }
        return result;
    }
};