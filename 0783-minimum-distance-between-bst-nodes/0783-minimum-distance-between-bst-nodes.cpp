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
    TreeNode *pre = NULL;
public:
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        
        solve(root, ans);
        return ans;
    }
    
    void solve(TreeNode *root, int &ans) {
        if(!root) return;
        
        solve(root->left, ans);
        if(pre) ans = min(ans, abs(root->val - pre->val));
        pre = root;
        
        solve(root->right, ans);
    }
};