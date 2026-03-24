#include <vector>
#include <queue>

using namespace std;
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
    // void bfs(TreeNode *root , vector<vector<int>> &res,int depth){
    //     if(!root)
    //         return;
    //     if(res.size() == depth)
    //         res.push_back({});
    //     res[depth].push_back(root->val);
    //     bfs(root->left,res,depth+1);
    //     bfs(root->right,res,depth+1);
    // }
    // vector<vector<int>> levelOrder(TreeNode *root)
    // {
    //     vector<vector<int>> res;
    //     if (!root)
    //         return res;
    //     bfs(root,res,0);
    //     return res;
    // }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size;i++){
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            res.push_back(level);
        }
        return res;
    }
};