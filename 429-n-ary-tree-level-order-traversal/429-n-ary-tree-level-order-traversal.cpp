/* class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
}; */

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        
        vector<vector<int>> ans;
        queue<Node*> q; q.push(root);
        
        while(q.size()) {
            int s = q.size();
            vector<int> curr;
            while(s--) {
                auto p = q.front(); q.pop();
                curr.push_back(p->val);
                for(auto &c: p->children) {
                    if(c) q.push(c);
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};