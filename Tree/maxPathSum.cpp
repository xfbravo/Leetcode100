#include <algorithm>
using namespace std;
#define INT_MIN -2147483648
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int dfs(TreeNode *root, int &maxSum){
        if(!root){
            return 0;
        }
        //以左孩子为根节点的最大路径和
        int leftMax = dfs(root->left, maxSum);
        //以右孩子为根节点的最大路径和
        int rightMax = dfs(root->right, maxSum);
        //以当前节点为根节点的最大路径和
        int currentMax = root->val + leftMax + rightMax;
        //更新全局最大路径和
        maxSum = max(maxSum, currentMax);
        //返回以当前节点为根节点的最大路径和，不能同时包含左右孩子
        return max(0,root->val + max(leftMax, rightMax));
    }
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
};