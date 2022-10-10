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
    int maxi = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        sum(root);
        
        return maxi;
    }
    
    int sum(TreeNode *root) {
        if(!root) 
            return 0;
        
        int left = max(sum(root->left), 0), right = max(sum(root->right), 0);
        
        maxi = max(maxi, root->val + left + right);
        return root->val + max(left, right);
    }
};