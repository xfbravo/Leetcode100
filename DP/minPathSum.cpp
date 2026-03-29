#include <vector>
using std::vector;

class solution{
public:
    //dp[i][j]一定是从dp[i-1][j]或者dp[i][j-1]移动过来
    //dp[i][j] += min(dp[i-1][j],dp[i][j-1])
    int minPathSum(vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 1; i < m;i++){
            grid[i][0] += grid[i - 1][0];
        }
        for (int j = 1; j < n;j++){
            grid[0][j] += grid[0][j - 1];
        }
        for (int i = 1; i < m;i++){
            for (int j = 1; j < n;j++){
                grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};