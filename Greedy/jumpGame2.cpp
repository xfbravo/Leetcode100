#include <vector>
#include <algorithm>
class Solution
{
public:
    int jump(std::vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return 0;
        int i = 0;
        int step = 0;
        int maxPos = 0;
        int currMax = 0;
        // 题目确保可以走到终点，所以直接while(1)不用考虑死循环
        // 否则要加一个判断if(currMax == maxPos&&maxPos!=n-1) return -1;
        // 表示走到currMax之后无法再向前走
        while (1)
        {   
            //一直向前走，走到currMax（表示step步可以到达的最远距离）
            while (i <= currMax)
            {
                //更新最远距离（step+1）步可以走到的最远距离
                maxPos = std::max(maxPos, i + nums[i]);
                if (maxPos >= n - 1)
                    return step + 1;
                i++;
            }
            //走到currMax后,进行下一轮循环，让currMax=maxPos
            currMax = maxPos;
            //表示多走了一步
            step++;
        }
        return step;
    }
};