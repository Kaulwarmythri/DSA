/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)  }; */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        bool flag = false;
        
        queue<TreeNode *> q; q.push(root);
        
        while(q.size()) {
            auto curr = q.front(); q.pop();
            if(curr->left) {
                if(flag) return false;
                q.push(curr->left);
            } else flag = true;
            if(curr->right) {
                if(flag) return false;
                q.push(curr->right);
            } else {
                flag = true;
            }
        }
        return true;
    }
};