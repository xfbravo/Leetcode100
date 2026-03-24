#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        if (fresh == 0)
            return 0;

        int minutes = 0;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty() && fresh > 0)
        {
            int sz = q.size();
            for (int k = 0; k < sz; k++)
            {
                auto cur = q.front();
                q.pop();
                int x = cur.first;
                int y = cur.second;

                for (int d = 0; d < 4; d++)
                {
                    int nx = x + dirs[d][0];
                    int ny = y + dirs[d][1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    if (grid[nx][ny] != 1)
                        continue;

                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx, ny});
                }
            }
            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};