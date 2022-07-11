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
    vector<int> ans;
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        
        solve(root, 0);
        return ans;
    }
    
    void solve(TreeNode *root, int height) {
        if(!root) return;
        
        if(ans.size() == height) ans.push_back(root->val);
        solve(root->right, height+1);
        solve(root->left, height+1);
    }
};