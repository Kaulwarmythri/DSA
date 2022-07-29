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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return deepest(root).second;
    }
    
    pair<int, TreeNode*> deepest(TreeNode *root) {
        if(!root) return {0, NULL};
        
        auto l = deepest(root->left), r = deepest(root->right);
        
        return {max(l.first, r.first)+1, l.first == r.first ? root : l.first > r.first ? l.second: r.second};
    }
};