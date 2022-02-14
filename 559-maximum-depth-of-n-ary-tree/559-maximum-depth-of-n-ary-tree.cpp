/*// Definition for a Node.
class Node {
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
};*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int max_depth = 0;
        for(auto node : root->children){
            max_depth = max(max_depth, maxDepth(node));
        }
        return ++max_depth;
        
    }
};