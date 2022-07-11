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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        
        postOrder(root, nodes);
        return nodes;
    }
    
    void postOrder(TreeNode *root, vector<int> &nodes) {
        if(!root) return;
        
        postOrder(root->left, nodes);
        postOrder(root->right, nodes);
        nodes.push_back(root->val);
    }
};