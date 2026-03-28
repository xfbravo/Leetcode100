#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> ans;
        //第一行的1
        ans.push_back(std::vector<int>{
            1,
        });
        for (int i = 1; i <= numRows;i++){
            //新加一行
            ans.push_back({});
            for (int j = 0; j <= i;j++){
                //如果是杨辉三角的最左边或者最右边的元素，那么加入1
                if(j == 0|| j == i ){
                    ans[i].push_back(1);
                }else{
                    //否则，加入上一行对应两个元素的和
                    ans[i].push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
                }
            }
        }
        return ans;
    }
};