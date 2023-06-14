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
    TreeNode *prev = NULL;
    int ans = INT_MAX;
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
    
    void inorder(TreeNode *root) {
        if(!root) return;
        inorder(root->left);
        
        if(prev) ans = min(ans, abs(root->val - prev->val));
        prev = root;
        
        inorder(root->right);
    }
};