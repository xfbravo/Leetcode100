#include <vector>
using namespace std;
class Solution
{
public:
    bool isConnected(vector<vector<char>> &grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0' ){
            return false;
        }
        grid[i][j] = '0';
        isConnected(grid,  i - 1, j);
        isConnected(grid, i + 1, j);
        isConnected(grid, i, j - 1);
        isConnected(grid, i, j + 1);
        return true;
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m;i++){
            for (int j = 0; j < n;j++){
                if(isConnected(grid, i, j)){
                    count++;
                }
            }
        }
        return count;
    }
};