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
    TreeNode *first = NULL, *mid = NULL, *last = NULL, *prev = NULL;
public:
    void recoverTree(TreeNode* root) {
        if(!root) return;
        recover(root, prev);
        
        if(first && last) {
            swap(&first->val, &last->val);
        } else if(first && mid) {
            swap(&first->val, &mid->val);
        }
    }
    
    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    } 
    
    void recover(TreeNode *root, TreeNode* &prev) {
        if(!root) return;
        
        recover(root->left, prev);
        if(prev) {
            if(prev->val >= root->val) {
                if(!first) {
                    first = prev;
                    mid = root;
                } else {
                    last = root;
                }
            }
        }
        prev = root;
        recover(root->right, prev);
    }
};