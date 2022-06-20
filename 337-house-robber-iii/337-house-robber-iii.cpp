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
        if(!root) return 0;
        pair<int, int> ans = robTree(root);
        
        return max(ans.first, ans.second);
    }
    
    pair<int, int> robTree(TreeNode *root) {
        if(!root) return {0, 0};
        
        pair<int, int> left = robTree(root->left), right = robTree(root->right);
        
        int include = left.second + right.second + root->val,
        exclude = max(left.first, left.second) + max(right.first, right.second);
        
        return {include, exclude};
    }
};