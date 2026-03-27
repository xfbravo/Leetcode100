#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> sk;
        for (char c : s)
        {
            switch (c)
            {
            case '(':
                sk.push(c);
                break;
            case '[':
                sk.push(c);
                break;
            case '{':
                sk.push(c);
                break;
            case ')':
            {
                if (!sk.empty() && sk.top() == '(')
                {
                    sk.pop();
                    break;
                }
                else
                    return false;
            }
            case ']':
            {
                if (!sk.empty() && sk.top() == '[')
                {
                    sk.pop();
                    break;
                }
                else
                    return false;
            }
            case '}':
            {
                if (!sk.empty() && sk.top() == '{')
                {
                    sk.pop();
                    break;
                }
                else
                    return false;
            }
            default:
                return false;
            }
        }
        return sk.empty();
    }
};