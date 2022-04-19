/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
 * };
 */
class Solution {
    TreeNode *prev;
public:
    int minDiffInBST(TreeNode* root) {
        prev = NULL;
        int ans = INT_MAX;
        traverse(root, ans);
        
        return ans;
    }
    
    void traverse(TreeNode *root, int &ans) {
        if(!root) return;
        
        traverse(root->left, ans);
        if(prev) ans = min(ans, abs(root->val - prev->val));
        prev = root;
        
        traverse(root->right, ans);
    }
};