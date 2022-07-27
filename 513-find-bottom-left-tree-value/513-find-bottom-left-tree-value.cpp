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
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = 0, leftVal = root->val;
        
        solve(root, maxDepth, leftVal, 0);
        
        return leftVal;
    }
    
    void solve(TreeNode *root, int &maxDepth, int &leftVal, int depth) {
        if(!root) return;
        
        solve(root->left, maxDepth, leftVal, depth+1);
        solve(root->right, maxDepth, leftVal, depth+1);
        
        if(depth > maxDepth) {
            maxDepth = depth;
            leftVal = root->val;
        }
    }
    
    
};