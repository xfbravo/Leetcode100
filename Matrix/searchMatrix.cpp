#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    //矩阵在任意位置的元素都比右边和下边的元素小，因此可以从矩阵的左上角开始进行搜索
    bool searchMatrix(vector<vector<int>> &matrix, int target){
        int m = matrix.size();
        int n = matrix[0].size();
        if(m*n == 0) return false;
        int i = 0, j = 0;
        while(i < m && j < n){
            if(matrix[i][j] == target) return true;
            //如果当前元素的右边元素小于等于目标值，并且右边元素的索引不越界，则向右移动
            if (j + 1 < n && matrix[i][j + 1] <= target)
                j++;
            //否则向下移动
            else if(i+1 < m){
                i++;
                //如果向下移动后元素大于目标值，则向左移动，直到找到一个小于等于目标值的元素或者越界
                while (j >= 0 && target < matrix[i][j])
                {
                    j--;
                    if(j<0) return false;
                    if(matrix[i][j] == target) return true;
                }
                
            }else{
                break;
            }
            
            
        }

        return false;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,4,7,11,15},
                                  {2,5,8,12,19},
                                  {3,6,9,16,22},
                                  {10,13,14,17,24},
                                  {18,21,23,26,30}};
    int target = 5;
    bool result = s.searchMatrix(matrix,target);
    cout << (result ? "true" : "false") << endl;
    return 0;
}