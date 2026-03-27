#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> st;
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            if (s[i] == '[')
            {
                st.push(s.substr(i, 1));
            }
            else if (s[i] == ']')
            {
                string subS = "";
                // 获取[]中的字符串
                while (st.top()[0] != '[')
                {
                    subS = st.top() + subS;
                    st.pop();
                }
                st.pop();
                // 获取[]前面的数字
                int num = 0;
                int digit = 1;
                while (!st.empty() && '0' <= st.top()[0] && st.top()[0] <= '9')
                {
                    num += (st.top()[0] - '0') * digit;
                    digit *= 10;
                    st.pop();
                }
                // 压入栈顶
                if (num == 0)
                {
                    st.push(subS);
                }
                else
                {
                    string temp = subS;
                    subS = "";
                    for (int i = 0; i < num; i++)
                    {
                        subS += temp;
                    }
                    st.push(subS);
                }
            }
            else
            {
                st.push(s.substr(i, 1));
            }
        }
        string ans = "";
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "3[a]2[bc]";
    string ans = sol.decodeString(s);
    cout << s << endl;
}