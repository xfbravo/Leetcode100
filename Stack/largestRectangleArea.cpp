#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/*
[3,6,5,7,4,8,1,0]
3,5         6
3,5,7       6
3,5         7
3,4         15
3,4,8       15
3,4         15
3           20
1           20    20>18
*/

class Solution
{
public:
    // 着重考虑栈内只剩一个元素的情况
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            // 如果栈顶元素大于新元素，那么可以知道以栈顶元素为高的最大面积
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                int height = heights[st.top()];
                int length = 1;
                st.pop();
                // 必须要先pop（），因为要知道当前元素的上一个元素的下标是多少
                // length = 该元素之前第一个小于自身的元素下标到该元素之后第一个小于自身元素的下表（左右都是开区间）
                if (st.size() > 0)
                {
                    length = i - st.top() - 1; // i-1-(st.top()+1)+1
                }
                else
                {
                    length = i;
                }

                int area = height * length;
                maxArea = max(maxArea, area);
            }
            // 否则，将新元素压入堆栈
            st.push(i);
        }
        // 最后只剩下一个从上向下递减的栈
        // 以栈顶元素为高的矩形向后一定可以延展的最后一个柱形
        while (st.size() > 1)
        {
            int height = heights[st.top()];
            st.pop();
            int length = n - st.top() - 1;
            int area = height * length;
            maxArea = max(maxArea, area);
        }
        // 只剩下一个最小的，以该元素为高，底可以延展至整个区间
        int area = heights[st.top()] * n;
        maxArea = max(maxArea, area);
        return maxArea;
    }
};