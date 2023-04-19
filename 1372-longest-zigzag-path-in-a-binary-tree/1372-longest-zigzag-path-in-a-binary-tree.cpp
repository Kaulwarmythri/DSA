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
    int ans = 0;
public:
    int longestZigZag(TreeNode* root) {
        dfs(root);
        
        return ans - 1;
    }
    
    vector<int> dfs(TreeNode *root) {
        if(!root) return {0, 0};
        
        int left = dfs(root->left)[1] + 1, right = dfs(root->right)[0] + 1;
        ans = max({ans, left, right});
        
        return {left, right};
    }
};