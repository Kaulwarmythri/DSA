/* * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) 
 };*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        queue<pair<TreeNode*, long>> q; q.push({root, 0});
        long maxWidth = 1;
        
        while(q.size()) {
            int s = q.size();
            long curr = 0;
            
            for(int i=0; i<s; i++) {
                auto p = q.front(); q.pop();
                if(!i) curr = p.second;
                else maxWidth = max(maxWidth, p.second - curr + 1);
                
                if(p.first->left) q.push({p.first->left, 2 * p.second - curr + 1});
                if(p.first->right) q.push({p.first->right, 2 * p.second - curr + 2});
            }
        }
        return maxWidth;
    }
};
