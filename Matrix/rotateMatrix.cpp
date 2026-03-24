#include <vector>

using namespace std;

class Solution{
public:
    void rotate(vector<vector<int>>&matrix){
        int n = matrix.size();
        //一圈一圈进行旋转，旋转的圈数为n/2
        for (int i = 0; i < n / 2;i++){
            //每一圈的旋转需要进行n-2*i-1次交换
            for (int j = i; j < n - i - 1;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};