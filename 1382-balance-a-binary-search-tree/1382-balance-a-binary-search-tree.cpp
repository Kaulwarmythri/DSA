/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} */
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;
        root->left = balanceBST(root->left);
        root->right = balanceBST(root->right);
        
        int balance = getBalance(root);
        
        if(balance > 1) {
           if(height(root->left->left) < height(root->left->right)) {
               root->left = leftRotate(root->left);
           }
           return balanceBST(rightRotate(root)); 
        
        
        } else if(balance < -1) {
            if(height(root->right->right) < height(root->right->left)) {
                root->right = rightRotate(root->right);
            }
            return balanceBST(leftRotate(root));
        }
        return root;            
    }
    
    int getBalance(TreeNode *root) {
        if(!root) return 0;
        return height(root->left) - height(root->right);
    }
    
    int height(TreeNode *root) {
        if(!root) return -1;
        return 1 + max(height(root->left), height(root->right));
    }
    
    TreeNode *leftRotate(TreeNode *x) {
        TreeNode *y = x->right, *T2 = y->left;
        y->left = x;
        x->right = T2;
        
        return y;
    }
    
    TreeNode *rightRotate(TreeNode *y) {
        TreeNode *x = y->left, *T3 = x->right;
        x->right = y;
        y->left = T3;
        
        return x;
    }
};