/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr)
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
 * };
 */
class Solution {
    
public:
    void traverse(TreeNode *root, string temp, string &res){
        if(!root) return;
        
        temp = char(root->val+97)+temp;
        if(!root->left && !root->right){
            if(res=="") res=temp;
            else res=min(res, temp);
        }
        else{
            traverse(root->left, temp, res);
            traverse(root->right, temp, res);
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        string res="";
        traverse(root, "", res);
        
        return res;
    }
};