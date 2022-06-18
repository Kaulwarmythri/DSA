/** * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode*left, TreeNode*right) : val(x), left(left), right(right){}
 * }; */

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return constructTrees(1, n);
    }
    
    vector<TreeNode *> constructTrees(int s, int e) {
        vector<TreeNode *> ans; 
        if(s > e) {
            ans.push_back(NULL);
            return ans;
        }
        if(s == e) {
            TreeNode *root = new TreeNode(s);
            ans.push_back(root);
            return ans;
        }
        
        for(int i=s; i<=e; i++) {
            vector<TreeNode *> left = constructTrees(s, i-1);
            vector<TreeNode *> right = constructTrees(i+1, e);
            
            for(auto l : left) {
                for(auto r : right) {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }   
        }
        return ans;
    }
};