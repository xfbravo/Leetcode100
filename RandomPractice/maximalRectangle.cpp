#include <vector>
#include <stack>
class Solution
{
public:
    // 采用Leetcode Hot 100/Stack/largestRectangleArea来计算矩形最大面积
    // 当前行中每个元素上面有多少连续的‘1’代表该列的height（包括当前元素本身）
    int maxArea(std::vector<int> &heights)
    {
        int n = heights.size();
        std::stack<int> st;
        int maxArea;
        for (int i = 0; i < n; i++)
        {
            // 如果栈顶元素大于新元素，那么可以知道以栈顶元素为高的最大面积
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                int height = heights[st.top()];
                int length = 1;
                st.pop();
                if (st.size() > 0)
                {
                    length = i - st.top() - 1; // i-1-(st.top()+1)+1
                }
                else
                {
                    length = i;
                }

                int area = height * length;
                maxArea = std::max(maxArea, area);
            }
            // 否则，将新元素压入堆栈
            st.push(i);
        }
        // 剩余的元素都是递增的（从栈顶向下递减），且以该元素起始的矩形一定能延申到数组尾部
        // 因为该位置的元素一定小于等于后面的元素，否则该元素会被弹出栈
        while (st.size() > 1)
        {
            int height = heights[st.top()];
            st.pop();
            int length = n - st.top() - 1;
            int area = height * length;
            maxArea = std::max(maxArea, area);
        }
        // 剩下一个最小的元素，这个元素为高的矩形能从头延申到尾部
        if (st.size() == 1)
        {
            int area = heights[st.top()] * n;
            maxArea = std::max(maxArea, area);
            st.pop();
        }
        return maxArea;
    }
    int maximalRectangle(std::vector<std::vector<char>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < rows; i++)
        {
            std::vector<int> heights;
            for (int j = 0; j < cols; j++)
            {
                int height = 0;
                for (int k = i; k >= 0; k--)
                {
                    if (matrix[k][j] == '0')
                    {
                        break;
                    }
                    else
                    {
                        height++;
                    }
                }
                heights.push_back(height);
            }
            int currArea = maxArea(heights);
            ans = std::max(ans, currArea);
        }
        return ans;
    }
};