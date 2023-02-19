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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        deque<TreeNode*> q; q.push_back(root);
        bool ltr = true;
        
        while(q.size()) {
            int s = q.size();
            vector<int> level;
            while(s--) {
                if(ltr) {
                    auto cur = q.back(); q.pop_back();
                    if(cur->left) q.push_front(cur->left);
                    if(cur->right) q.push_front(cur->right);
                    level.push_back(cur->val);
                    
                } else {
                    auto cur = q.front(); q.pop_front();
                    if(cur->right) q.push_back(cur->right);
                    if(cur->left) q.push_back(cur->left);
                    level.push_back(cur->val);
                }
            }
            ltr = !ltr;
            ans.push_back(level);
        }
        return ans;
    }
};