/*class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};*/

class Solution {
    int n;
public:
    Node* construct(vector<vector<int>>& G) {
        n = G.size();
        return solve(G, 0, n-1, 0, n-1);
    }
    
    Node *solve(vector<vector<int>> &G, int rs, int re, int cs, int ce) {
        if(rs > re || cs > ce) return NULL;
        
        int val = G[rs][cs];
        bool leaf = true;
        for(int i=rs; i<=re; i++) {
            for(int j=cs; j<=ce; j++) {
                if(G[i][j] != val) {
                    leaf = false;
                    break;
                }
            }
            if(!leaf) break;
        }
        
        if(leaf) return new Node(val, true);
        
        int r_mid = (rs + re) / 2, c_mid = (cs + ce) / 2;
        
        Node *topLeft = solve(G, rs, r_mid, cs, c_mid);
        Node *topRight = solve(G, rs, r_mid, c_mid + 1, ce);
        Node *bottomLeft = solve(G, r_mid + 1, re, cs, c_mid);
        Node *bottomRight = solve(G, r_mid + 1, re, c_mid + 1, ce);
        
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};