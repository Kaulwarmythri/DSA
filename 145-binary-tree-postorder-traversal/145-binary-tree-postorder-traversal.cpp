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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode *> s; s.push(root);
        
        while(s.size()) {
            auto curr = s.top();
            if(curr == nullptr) {
                s.pop();
                ans.push_back(s.top()->val);
                s.pop();
                continue;
            }
            s.push(nullptr);
            if(curr->right) s.push(curr->right);
            if(curr->left) s.push(curr->left);
        }
        return ans;
    }
};