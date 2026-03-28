#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {

        // vector<int> mp(26, -1);
        int mp[26] = {-1};
        int sSize = s.size();
        for (int i = 0; i < sSize; i++)
        {
            mp[s[i] - 'a'] = i;
        }
        vector<int> ans;
        int i = 0;
        int currMax = 0;
        while (i < sSize)
        {
            currMax = mp[s[i] - 'a'];
            if (currMax >= sSize)
            {
                ans.push_back(sSize - i);
                return ans;
            }
            int size = 1;
            i++;
            while (i <= currMax)
            {
                currMax = max(currMax, mp[s[i] - 'a']);
                i++;
                size++;
            }
            ans.push_back(size);
        }
        return ans;
    }
};