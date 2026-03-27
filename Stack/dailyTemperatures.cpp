#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures){
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n;i++){
            while(!st.empty()&&temperatures[st.top()]<temperatures[i]){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};



int main() {
    Solution s;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = s.dailyTemperatures(temperatures);

    return 0;
}