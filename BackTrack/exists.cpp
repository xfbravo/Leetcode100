#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    //index表示字母下标
    void backtrack(vector<vector<char>> &board,int index, const string &word, int row, int col, bool &result)
    {
        if(result)
            return;
        //board[row][col]表示要新加的字母
        int m = board.size(), n = board[0].size();
        if (row < 0 || row == m || col < 0 || col == n || board[row][col] == '#'|| board[row][col] != word[index])
        {
            return;
        }
        //加入新字母
        char newLetter = board[row][col];
        board[row][col] = '#';

        //如果找到了，就返回
        if (word.size()-1 == index)
        {
            result = true;
            return;
        }

        backtrack(board,index+1, word, row - 1, col, result);
        backtrack(board, index + 1, word, row + 1, col, result);
        backtrack(board, index + 1, word, row, col - 1, result);
        backtrack(board, index + 1, word, row, col + 1, result);
        board[row][col] = newLetter;
    };
    bool exist(vector<vector<char>> &board, string word)
    {
        bool result = false;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m;i++){
            for (int j = 0; j < n;j++){
                if(board[i][j] == word[0]){
                    backtrack(board, 0, word, i, j, result);
                    if(result)
                        return true;
                }
            }
        }
            return result;
    }
};