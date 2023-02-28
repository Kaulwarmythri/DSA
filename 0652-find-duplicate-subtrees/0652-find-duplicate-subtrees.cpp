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
    unordered_map<string, int> m;
    vector<TreeNode*> ans;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        
        return ans;
    }
    
    string solve(TreeNode *root) {
        if(!root) return "$";
        
        string left = solve(root->left), right = solve(root->right);
        
        string s = to_string(root->val) + "$" + left + "$" + right;
        if(m[s] == 1) ans.push_back(root);
        m[s]++;
        
        return s;
    }
};