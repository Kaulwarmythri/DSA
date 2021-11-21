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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size(), p=0;
        for(int i=0;i<n;i++) m[inorder[i]] = i;
        return makeTree(preorder, inorder, 0, n-1, p);
    }
    TreeNode* makeTree(vector<int> &pre, vector<int> &in, int l, int r, int &idx){
        if(l>r) return NULL;
        
        TreeNode *root = new TreeNode(pre[idx++]);
        
        int i=m[root->val];
        root->left = makeTree(pre, in, l, i-1, idx);
        root->right = makeTree(pre, in, i+1, r, idx);
        
        return root;
        
    }
};