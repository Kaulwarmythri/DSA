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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode *, long>> q;
        q.push({root, 0});
        long max_width = 1;
        while(!q.empty()){
            int size = q.size();
            long curr = 0;
            for(int i=0; i<size; i++){
                auto p = q.front(); q.pop();
                if(i == 0) curr = p.second;
                else max_width = max(max_width, p.second-curr+1);
                
                if(p.first->left) q.push({p.first->left, p.second*2 - curr});
                if(p.first->right) q.push({p.first->right, p.second*2 - curr + 1});
            }
        }
        return max_width;
    }
};