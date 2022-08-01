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
class CBTInserter {
    TreeNode *root;
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
    }
    
    int insert(int val) {
        TreeNode* curr;
        queue<TreeNode *> q; q.push(root);
        
        while(q.size()) {
            curr = q.front(); q.pop();
            if(!curr->left) {
                curr->left = new TreeNode(val);
                break;
            }
            if(!curr->right) {
                curr->right = new TreeNode(val);
                break;
            }
            q.push(curr->left);
            q.push(curr->right);
        }
        return curr->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */