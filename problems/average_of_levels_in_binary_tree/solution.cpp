/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);
        
        while(q.size()){
            double avg = 0;
            
            queue<TreeNode *> temp;
            int size = q.size();
            while(q.size()){
                auto curr = q.front(); q.pop();
                avg += curr->val;
                if(curr->left) temp.push(curr->left); 
                if(curr->right) temp.push(curr->right);
            }
            ans.push_back(avg/size);   
            q = temp;
        }
        return ans;
    }
};