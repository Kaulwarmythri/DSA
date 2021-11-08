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
    vector<TreeNode*> constructTrees(int start, int end){
        vector<TreeNode*> result;
        if(start==end){
            TreeNode *root = new TreeNode(start);
            result.push_back(root);
            return result;
        }
        if(start>end){
            result.push_back(NULL);
            return result;
        }
        
        for(int i=start;i<=end;i++){
            vector<TreeNode*> leftTrees = constructTrees(start, i-1);
            vector<TreeNode*> rightTrees = constructTrees(i+1, end);
            
            for(auto l: leftTrees){
                for(auto r: rightTrees){
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        return result;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        return constructTrees(1, n);
    }
};