#include <vector>
#include <iostream>
#include <stack>
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
    // bool inorder(TreeNode *root , vector<int> &v, int k){
    //     if(!root)
    //         return false;
    //     if(inorder(root->left,v,k))
    //         return true;
    //     v.push_back(root->val);
    //     if(v.size() == k)
    //         return true;
    //     return inorder(root->right,v,k);
    // }
    // int kthSmallest(TreeNode *root, int k)
    // {
    //     vector<int> v;
    //     inorder(root, v, k);
    //     return v.back();
    // }
    int kthSmallest(TreeNode *root,int k){
        stack<TreeNode *> s;
        while(root != nullptr || !s.empty()){
            while(root!=nullptr){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            k--;
            if(k==0){
                return root->val;
            }
            root = root->right;
        }
        return -1;
    }
};

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    Solution s;
    cout<<s.kthSmallest(root, 1)<<endl;
}