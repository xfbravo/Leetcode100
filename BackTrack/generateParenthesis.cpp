#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void backtrack(vector<string> &result,string curr,int left,int right){
        if(left<0||right<0)
            return;
        if(left>right)
            return;
        if(left==0&& right ==0){
            result.push_back(curr);
            return;
        }
        if(left>0)
            backtrack(result, curr + "(", left - 1, right);
        if(right>left)
            backtrack(result, curr + ")", left, right - 1);
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        backtrack(result, "", n, n);
        return result;
    }
};