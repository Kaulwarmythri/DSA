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
    unordered_map<int, int> m;
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = post.size();
        
        for(int i=0; i<n; i++) m[post[i]] = i;
        
        int idx = 0;
        
        return constructTree(pre, post, 0, n-1, idx);
    }
    
    TreeNode *constructTree(vector<int> &pre, vector<int> &post, int l, int r, int &idx) {
        if(l > r) return NULL;
        
        if(l == r) return new TreeNode(pre[idx++]);
        
        TreeNode *root = new TreeNode(pre[idx++]);
        
        int i = m[pre[idx]];
        root->left = constructTree(pre, post, l, i, idx);
        root->right = constructTree(pre, post, i+1, r-1, idx);
        
        return root;
    }
};