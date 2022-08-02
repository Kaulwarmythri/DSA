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
    TreeNode* sufficientSubset(TreeNode* root, int X) {
        if(!root) return NULL;
        return solve(root, X);
    }
    
    TreeNode *solve(TreeNode *root, int X, int sum = 0) {
        if(!root) return NULL;
        
        sum += root->val;
        
        if(!root->left && !root->right) {
            if(sum < X) {
                delete root;
                return NULL;
            }
            return root;
        }
        root->left = solve(root->left, X, sum);
        root->right = solve(root->right, X, sum);
        
        if(!root->left && !root->right) return NULL;
        return root;
    }
};