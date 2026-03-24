#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string getLetter(char c)
    {
        switch (c)
        {
        case '2':
            return "abc";
        case '3':
            return "def";
        case '4':
            return "ghi";
        case '5':
            return "jkl";
        case '6':
            return "mno";
        case '7':
            return "pqrs";
        case '8':
            return "tuv";
        case '9':
            return "wxyz";
        default:
            return "";
        }
    }
    void backtrack(vector<string> letters, string curr, vector<string> &result, int t, int n)
    {
        if (t == n)
        {
            result.push_back(curr);
        }
        else
        {
            for (int i = 0; i < letters[t].size();i++){
                backtrack(letters, curr + letters[t][i], result, t + 1, n);
            }
        }
    };
    vector<string> letterCombinations(string digits)
    {
        int n = digits.length();
        vector<string> letters;
        for (char c : digits)
        {
            letters.push_back(getLetter(c));
        }
        vector<string> result;
        backtrack(letters, "", result, 0, n);
        return result;
    }
};