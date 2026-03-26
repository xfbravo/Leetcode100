#include <vector>
#include <string>
using namespace std;

// class Solution
// {
// public:
//     // index是新插入列得皇后的位置
//     bool valid(vector<string> &curr, int index, int depth, int n)
//     {
//         for (int i = 0; i < depth; i++)
//         {
//             // 查看该列有没有
//             if (curr[i][index] == 'Q')
//             {
//                 return false;
//             }
//         }
//         int i = depth - 1;
//         // 查看右斜方
//         while (i>=0)
//         {
//             if (index + depth - i >= n)
//                 break;
//             if (curr[i][index + depth - i] == 'Q')
//             {
//                 return false;
//             }
//             i--;
//         }
//         //查看左斜方
//         i = depth - 1;
//         while(i>=0){
//             if(index-depth+i<0)
//                 break;
//             if(curr[i][index-depth+i] == 'Q'){
//                 return false;
//             }
//             i--;
//         }
//         return true;
//     };
//     string generateLine(int index, int n)
//     {
//         string line = "";
//         for (int i = 0; i < n; i++)
//         {
//             if (i != index)
//             {
//                 line += ".";
//             }
//             else
//             {
//                 line += "Q";
//             }
//         }
//         return line;
//     }
//     void backtrack(vector<vector<string>> &result, vector<string> &curr, int depth, int n)
//     {
//         if (depth == n)
//         {
//             result.push_back(curr);
//             return;
//         }
//         for (int i = 0; i < n; i++)
//         {
//             if (valid(curr, i, depth, n))
//             {
//                 string line = generateLine(i, n);
//                 curr.push_back(line);
//                 backtrack(result, curr, depth + 1, n);
//                 curr.pop_back();
//             }
//         }
//     };
//     vector<vector<string>> solveNQueens(int n)
//     {
//         vector<vector<string>> result;
//         vector<string> curr;
//         backtrack(result, curr, 0, n);
//         return result;
//     }
// };
class Solution{
public:
    void backtrack(int row,int n,vector<string> &board,vector<bool> &col,vector<bool> &diag1,vector<bool> &diag2,vector<vector<string>> &ans){
        if(row == n){
            ans.push_back(board);
        }
        for (int i = 0; i < n;i++){
            int d1 = i + row;
            int d2 = i + n - row - 1;
            if(col[i]||diag1[d1]||diag2[d2])
                continue;
            col[i] = diag1[d1] = diag2[d2] = true;
            board[row][i] = 'Q';
            backtrack(row + 1, n, board, col, diag1, diag2, ans);
            board[row][i] = '.';
            col[i] = diag1[d1] = diag2[d2] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);
        backtrack(0, n, board, col, diag1, diag2, ans);
        return ans;
    }
};