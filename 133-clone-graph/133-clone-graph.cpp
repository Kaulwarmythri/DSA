/* // Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(node->neighbors.size() == 0){
            Node *newNode = new Node(node->val);
            return newNode;
        }
        unordered_map<int, Node *> m;
        return dfs(node, m);
    }
    
    Node *dfs(Node *node, unordered_map<int, Node *> &m){
        Node *newNode = new Node(node->val);
        
        m.insert({node->val, newNode});
        for(auto curr : node->neighbors) {
            auto it = m.find(curr->val);
            
            if(it == m.end()) {
                Node *currNode = dfs(curr, m);
                newNode->neighbors.push_back(currNode);
            } else {
                newNode->neighbors.push_back(it->second);
            }
        }
        
        return newNode;
    }
};