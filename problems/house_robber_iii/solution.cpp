/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) 
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*, int> dp;
public:
    int rob(TreeNode* root) {
        return robHelper(root);
    }
    
    int robHelper(TreeNode* root){
        if(!root) return 0;
        int val= 0;
        if(dp.find(root) != dp.end()) return dp.at(root);
        
        if(root->right) val+= robHelper(root->right->right)+ robHelper(root->right->left);
        
        if(root->left) val+= robHelper(root->left->right)+ robHelper(root->left->left);
        
        val = max(root->val+ val, robHelper(root->right)+robHelper(root->left));
        dp[root]= val;
        return val;
    }
};