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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> vis;
        
        queue<TreeNode*> q; q.push(root);
        
        while(!q.empty()) {
            auto curr = q.front(); q.pop();
            if(curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        
        q.push(target); vis[target] = true;
        
        int currDis = 0;
        
        while(!q.empty()) {
            int s = q.size();
            if(currDis++ == k) break;
            
            while(s--) {
                auto curr = q.front(); q.pop();
                
                if(curr->left && !vis[curr->left]) {
                    vis[curr->left] = true;
                    q.push(curr->left);
                }
                if(curr->right && !vis[curr->right]) {
                    vis[curr->right] = true;
                    q.push(curr->right);
                }
                if(parent[curr] && !vis[parent[curr]]) {
                    vis[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty()) {
            auto curr = q.front(); q.pop();
            
            ans.push_back(curr->val);
        }
        return ans;
    }
};