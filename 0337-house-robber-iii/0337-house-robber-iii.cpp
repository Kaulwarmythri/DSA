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
public:
    int rob(TreeNode* root) {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
    
    pair<int, int> solve(TreeNode *root) {
        if(!root) return {};
        
        pair<int, int> left = solve(root->left), right = solve(root->right);
        
        int inc = root->val + left.second + right.second,
        exc = max(left.first, left.second) + max(right.first, right.second);
        
        return {inc, exc};
    }
};