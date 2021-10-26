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
    int sum=0;
    
    void addLeftLeaves(TreeNode *root, bool left){
        if(root != NULL){
            if(root->left==NULL && root->right==NULL && left==true) sum+=root->val;
            addLeftLeaves(root->left, true);
            addLeftLeaves(root->right, false);
        }
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return sum;
        addLeftLeaves(root, false);
        return sum;
        
    }
};