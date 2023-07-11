/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* X, int k) {
        unordered_map<TreeNode*, TreeNode*> par;
        
        unordered_map<TreeNode*, bool> vis;
        
        queue<TreeNode*> q; q.push(root);
        
        while(q.size()) {
            auto cur = q.front(); q.pop();
            
            if(cur->left) {
                q.push(cur->left);
                par[cur->left] = cur;
            }
            
            if(cur->right) {
                q.push(cur->right);
                par[cur->right] = cur;
            }
        }
        
        q.push(X); vis[X] = true;
        
        while(q.size()) {
            int s = q.size();
            
            if(k-- == 0) break;
            while(s--) {
                auto cur = q.front(); q.pop();
                
                if(par.find(cur) != par.end() && !vis[par[cur]]) {
                    q.push(par[cur]);
                    vis[par[cur]] = true;
                }
                
                if(cur->left && !vis[cur->left]) {
                    q.push(cur->left);
                    vis[cur->left] = true;
                }
                
                if(cur->right && !vis[cur->right]) {
                    q.push(cur->right);
                    vis[cur->right] = true;
                }
            }
        }
        vector<int> ans;
        while(q.size()) {
            auto cur = q.front(); q.pop();
            ans.push_back(cur->val);
        }
        return ans;
    }
};