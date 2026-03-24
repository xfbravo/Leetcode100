#include <vector>
using namespace std;

class Solution
{
public:
    void backtrack(vector<int> &candidates,vector<int> &combination,vector<vector<int>> &result,int &currSum,int index,int target){
        if(currSum>target){
            return;
        }
        if(currSum == target){
            result.push_back(combination);
        }else{
            for (int i = index; i < candidates.size();i++){
                int candidate = candidates[i];
                combination.push_back(candidate);
                currSum += candidate;
                backtrack(candidates, combination, result, currSum,i, target);
                currSum -= candidate;
                combination.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> combination;
        int currSum = 0;
        backtrack(candidates, combination, result,currSum ,0, target);
        return result;
    }
};