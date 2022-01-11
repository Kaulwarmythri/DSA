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
    void dfs(TreeNode* root, int parent ,int val, int depth, pair<int, int>& p){
        if(root){
            if(root->val == val){
                p = make_pair(parent, depth);
                return;
            } 
            dfs(root->left, root->val, val, depth+1, p);
            dfs(root->right, root->val, val, depth+1, p);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int, int> p1, p2;
        dfs(root, -1, x, 0, p1);
        dfs(root, -1, y, 0, p2);
        return (p1.first != p2.first) && (p1.second == p2.second);
    }
};



