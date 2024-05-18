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
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        postOrder(root, moves);
        
        return moves;
    }
    
    int postOrder(TreeNode *root, int &moves) {
        if(!root)
            return 0;
        int left = postOrder(root->left, moves), right = postOrder(root->right, moves);
        moves += abs(left) + abs(right);  //whether coins come from child to parent or have to go from parent to child, count them.
        return root->val - 1 + left + right;
    }
};