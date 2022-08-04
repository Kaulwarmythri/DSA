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
    int left, right;
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        count(root, x);
        
        return max({left, right, n - left - right -1}) > n/2;
    }
    
    int count(TreeNode *root, int x) {
        if(!root) return 0;
        int l = count(root->left, x), r = count(root->right, x);
        
        if(root->val == x) left = l, right = r;
        return l + r + 1;
    }
};