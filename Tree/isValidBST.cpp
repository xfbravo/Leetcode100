#include <vector>
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
#define LONG_MIN -2147483649
#define LONG_MAX 2147483648
class Solution
{
public:
    // bool inOrder(TreeNode *root ,vector<int> &v){
    //     if(!root)
    //         return true;
    //     bool res = true;
    //     res =inOrder(root->left,v)&& res;
    //     if(!res)
    //         return false;
    //     if(!v.empty() && v.back()>=root->val)
    //         return false;
    //     v.push_back(root->val);
    //     res =inOrder(root->right,v)&& res;
    //     return res;
    // }
    // bool isValidBST(TreeNode *root)
    // {
    //     bool res = true;
    //     vector<int> s;
    //     res = inOrder(root,s);
    //     return res;
    // }
    bool recurse(TreeNode *root, long min, long max){
        if(!root)
            return true;
        if(root->val<=min|| root->val>=max){
            return false;
        }
        bool left = recurse(root->left,min,root->val);
        bool right = recurse(root->right,root->val,max);
        return left && right;
    }
    bool isValidBST(TreeNode *root){
        return recurse(root, LONG_MIN, LONG_MAX);
    } 
};