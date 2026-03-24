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
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        //将左子树和右子树分别拉平
        if (root->left)
        {
            flatten(root->left);
        }
        if (root->right)
        {
            flatten(root->right);
        }
        //将左子树接到右子树上
        if(root->left){
            //获取左子树的最右节点
            TreeNode *leftEnd=root->left;
            while(leftEnd->right){
                leftEnd=leftEnd->right;
            }
            //将右子树接到左子树的最右节点上
            leftEnd->right=root->right;
            //将左子树接到右子树上
            root->right=root->left;
            root->left=nullptr;
        }
    };
};