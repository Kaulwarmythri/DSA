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
    map<int, int> m;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(), p=n-1;
        for(int i=0;i<n;i++) m[inorder[i]] = i;
        return constructTree(inorder, postorder, 0, n-1, p);
    }
    
    TreeNode* constructTree(vector<int>&in, vector<int>&post, int l, int r, int &idx)     {
        if(l > r) return NULL;
        
        TreeNode *root = new TreeNode(post[idx--]);
        int i=m[root->val];
        root->right = constructTree(in, post, i+1, r, idx);
        root->left = constructTree(in, post, l, i-1, idx);
        
        return root;
        
    }
};
