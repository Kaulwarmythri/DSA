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
public:
    void traverse(TreeNode *root, int num, int &result){
        if(!root) return; 
        
        num=num*10+root->val;
        //If reached the last node
        if(!root->left && !root->right){
            result+=num;
        }
        else{
            traverse(root->left, num, result);
            traverse(root->right, num, result);
        }
    }
    int sumNumbers(TreeNode* root) {
        int result=0;
        traverse(root, 0, result);
        
        return result;
        
        
    }
    
    
};