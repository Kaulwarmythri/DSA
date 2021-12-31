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
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
    
    int dfs(TreeNode *root, int minV, int maxV){
        
        if(!root) return maxV - minV;
        minV = min(minV, root->val);
        maxV = max(maxV, root->val);
        
        return max(dfs(root->left, minV, maxV), dfs(root->right, minV, maxV));
    }
};