/*
一棵圣诞树记作根节点为 root 的二叉树，节点值为该位置装饰彩灯的颜色编号。请按照从左到右的顺序返回每一层彩灯编号，每一层的结果记录于一行
简单层序遍历
*/
#include <vector>
#include <queue>
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
    std::vector<std::vector<int>> decorateRecord(TreeNode *root)
    {
        std::vector<std::vector<int>> result;
        if (!root)
        {
            return result;
        }
        std::queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            std::vector<int> level;
            for (int i = 0; i < size;i++){
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};
