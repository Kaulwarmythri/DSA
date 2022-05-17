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
    TreeNode *ans;
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        traverse(original, cloned, target);
        
        return ans;    
    }
    
    void traverse(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        if(original) {
            traverse(original->left, cloned->left, target);
            
            if(original == target) {
                ans = cloned;
                return;
            }
            traverse(original->right, cloned->right, target);
        }
    }
};