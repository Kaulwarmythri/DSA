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
    int sumEvenGrandparent(TreeNode* root, int par = 1, int gpar = 1) {
        return root ? sumEvenGrandparent(root->left, root->val, par) + sumEvenGrandparent(root->right, root->val, par) + ((gpar % 2 == 0) ? root->val : 0) : 0;
    }
};