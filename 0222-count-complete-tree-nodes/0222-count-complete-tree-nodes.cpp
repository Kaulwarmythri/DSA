/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} };*/
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        TreeNode *curr = root; int l = 1, r = 1;
        while((curr = curr->left)) 
            l++;
        curr = root;
        while((curr = curr->right)) 
            r++;
        return root == NULL ? 0 : 1 + countNodes(root->left) + countNodes(root->right);    
    }
};