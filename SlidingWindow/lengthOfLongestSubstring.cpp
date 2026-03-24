#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int max_length = 0;
        int left = 0;
        int right = 0;
        int n = s.size();
        while (right<n){
            for (int i = left; i < right;i++){
                if(s[i] == s[right]){
                    left = i+1;
                    break;
                }
            }
            max_length = max(max_length, right - left + 1);
            right++;
        }
        return max_length;
    }
};

int main(){
    Solution solution;
    string s = "abba";
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}