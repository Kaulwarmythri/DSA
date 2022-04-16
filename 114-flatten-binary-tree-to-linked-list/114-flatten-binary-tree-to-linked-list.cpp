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
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode *temp_left = root->left, *temp_right = root->right;
        
        root->left = NULL;
        
        flatten(temp_left);
        flatten(temp_right);
        
        root->right = temp_left;
        TreeNode *curr = root;
        while(curr->right != NULL) curr = curr->right;
        curr->right = temp_right;
    }
};