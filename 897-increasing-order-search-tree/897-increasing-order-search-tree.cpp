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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *dummy = new TreeNode(0), *temp = dummy;
        
        inorder(root, temp);
        return dummy->right;
    }
    
    TreeNode* inorder(TreeNode *root, TreeNode *temp) {
        if(!root) return temp;
        temp = inorder(root->left, temp);
        temp->right = root;
        root->left = NULL;
        temp = root;
        
        return inorder(root->right, temp);
    }
};