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
    int ans = 0;
public:
    int minCameraCover(TreeNode* root) {
        if(dfs(root) < 1) ans++;
        
        return ans;
    }
    
    int dfs(TreeNode *root) {
        if(!root) return 1;
        int left = dfs(root->left), right = dfs(root->right);
        
        if(left == 0 || right == 0) {
            ans++;
            return 2;
        } else if(left == 2 || right == 2) return 1;
        
        else return 0;
        
        return -1;
    }
};