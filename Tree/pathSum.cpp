#include <unordered_map>
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
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        //前缀和
        unordered_map<long long, int> prefixSumCount;
        prefixSumCount[0] = 1;
        long long currentSum = 0;
        int count = 0;
        dfs(root, targetSum, currentSum, prefixSumCount, count);
        return count;
    }
    void dfs(TreeNode *root, int targetSum, long long currentSum, unordered_map<long long, int> &prefixSumCount, int &count)
    {
        if(!root){
            return;
        }
        currentSum += root->val;
        //检查是否存在前缀和为currentSum - targetSum的路径
        //targetSum = currentSum(当前路径的前缀和) - prefixSum(之前某个节点的前缀和)
        //当prefixSum为currentSum - targetSum时，说明存在一条路径的和为targetSum
        if(prefixSumCount.count(currentSum - targetSum)){
            count += prefixSumCount[currentSum - targetSum];
        }
        prefixSumCount[currentSum]++;
        dfs(root->left, targetSum, currentSum, prefixSumCount, count);
        dfs(root->right, targetSum, currentSum, prefixSumCount, count);
        prefixSumCount[currentSum]--; //回退当前路径的前缀和计数，避免影响其他路径的计算
    }

};