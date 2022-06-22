/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    map<TreeNode *, int> dp;
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        
        if(dp.find(root) != dp.end()) return dp[root];
        
        int included = root->val, excluded = rob(root->left) + rob(root->right);
        
        if(root->left) included += rob(root->left->left) + rob(root->left->right);
        if(root->right) included += rob(root->right->left) + rob(root->right->right);
        
        return dp[root] = max(included, excluded);
         
    }
};