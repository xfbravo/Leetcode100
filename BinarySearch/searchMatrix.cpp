#include <vector>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int right = rows * cols;
        int left = 0;
        int mid = left + (right - left) / 2;
        while (right > left)
        {
            mid = left + (right - left) / 2;
            int row = mid / cols;
            int col = mid % cols;
            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] > target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return false;
    }
};