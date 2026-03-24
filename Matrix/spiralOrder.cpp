#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        while(left<right && top<bottom){
            for (int i = left; i < right;i++){
                res.push_back(matrix[top][i]);
            }
            for(int i=top;i<bottom;i++){
                res.push_back(matrix[i][right]);
            }
            for (int i = right; i > left;i--){
                res.push_back(matrix[bottom][i]);
            }
            for(int i=bottom;i>top;i--){
                res.push_back(matrix[i][left]);
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        if(left == right){
            for (int i = top; i <= bottom;i++){
                res.push_back(matrix[i][left]);
            }
        }
        else if(top == bottom){
            for (int i = left; i <= right;i++){
                res.push_back(matrix[top][i]);
            }
        }
        return res;
    }
}; 