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
    int n;
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        n = nums.size();
        return constructTree(nums, 0, n-1);
    }
    
    TreeNode *constructTree(vector<int> &nums, int l, int r) {
        if(l > r) return NULL;
        
        int mid = l + (r - l)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = constructTree(nums, l, mid-1);
        root->right = constructTree(nums, mid+1, r);
        
        return root;
    }
};