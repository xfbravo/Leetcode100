#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> inOrder(TreeNode* root, vector<int>& result){
        if(root == nullptr)
            return result;
        inOrder(root->left, result);
        result.push_back(root->val);
        inOrder(root->right, result);
        return result;
    }
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> result;
        return inOrder(root, result);
    }
};