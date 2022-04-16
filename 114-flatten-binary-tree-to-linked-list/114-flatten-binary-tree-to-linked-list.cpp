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
        if(root==nullptr) return;
        
        TreeNode* l = root->left; root->left = nullptr;
        TreeNode* r = root->right;
        
        flatten(l);
        flatten(r);
        
        root->right = l;
        TreeNode* cur = root;
        while(cur->right != nullptr) cur=cur->right;
        cur->right = r;
    }
};