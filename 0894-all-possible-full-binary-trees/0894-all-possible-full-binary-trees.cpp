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
    unordered_map<int, vector<TreeNode*>> dp;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        
        if(!n || !(n % 2))
            return ans;
        
        if(dp.find(n) != dp.end())
            return dp[n];
        
        if(n == 1) {
            TreeNode *root = new TreeNode(0);
            ans.push_back(root);
            return ans;
        }
        
        for(int i=1; i<n; i+=2) {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n - i - 1);
            
            for(auto &l: left) {
                for(auto &r: right) {
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    
                    ans.push_back(root);
                }
            }
        }
        return dp[n] = ans;
    }
};