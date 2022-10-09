/** Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }; */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> par;
        unordered_map<TreeNode*, bool> vis;
        
        queue<TreeNode*> q; q.push(root);
        
        while(q.size()) {
            auto curr = q.front(); q.pop();
            if(curr->left) {
                q.push(curr->left);
                par[curr->left] = curr;
            } 
            if(curr->right) {
                q.push(curr->right);
                par[curr->right] = curr;
            }
        }
        
        q.push(target); vis[target] = true;
        int dis = 0;
        while(q.size()) {
            int s = q.size();
            if(dis++ == k) break;
            while(s--) {
                auto curr = q.front(); q.pop();
                
                if(curr->left && !vis[curr->left]) {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right]) {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(par.find(curr) != par.end() && !vis[par[curr]]) {
                    q.push(par[curr]);
                    vis[par[curr]] = true;
                }
            }
        }
        vector<int> ans;
        while(q.size()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }
};