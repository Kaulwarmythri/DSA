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
    void binaryTreePaths(vector<string> &res, TreeNode *root, string t){
        if(!root->left && !root->right){
            res.push_back(t);
            return;
        }
        if(root->left) binaryTreePaths(res, root->left, t+"->"+to_string(root->left->val));
        if(root->right) binaryTreePaths(res, root->right, t+"->"+to_string(root->right->val));
                
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        binaryTreePaths(res, root, to_string(root->val));
        return res;
    }
};