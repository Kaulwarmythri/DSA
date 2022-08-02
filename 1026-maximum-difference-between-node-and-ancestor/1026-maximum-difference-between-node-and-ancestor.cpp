/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) }; */
class Solution {
    int ans = 0;
public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        
        return ans;
    }
    
    void dfs(TreeNode *root, int currMin, int currMax) {
        if(!root) return;
        
        ans = max({ans, root->val - currMin, currMax - root->val});
        
        currMin = min(currMin, root->val);
        currMax = max(currMax, root->val);
        dfs(root->left, currMin, currMax);
        dfs(root->right, currMin, currMax);
        
        
    }
};