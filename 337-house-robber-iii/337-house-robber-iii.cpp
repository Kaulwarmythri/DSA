/* * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} * }; */

class Solution {
    map<TreeNode *, int> dp;
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        
        int include = root->val, exclude = 0;
        
        if(dp.find(root) != dp.end()) return dp[root];
        
        if(root->left) {
            include += rob(root->left->left) + rob(root->left->right);
            exclude += rob(root->left);
        }
        
        if(root->right) {
            include += rob(root->right->left) + rob(root->right->right);
            exclude += rob(root->right);
        }
        
        return dp[root] = max(include, exclude);
    }
};