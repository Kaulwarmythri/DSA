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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        
        TreeNode *curr = root;
        while(curr) {
            if(!curr->left) {
                nodes.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode *pre = curr->left;
                while(pre->right && pre->right != curr) 
                    pre = pre->right;
                if(!pre->right) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    nodes.push_back(curr->val);
                    pre->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return nodes;
    }
};