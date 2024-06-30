class Solution {
public:
    int findCenter(vector<vector<int>>& E) {
        unordered_set<int> vertices;
        
        for(auto &e: E) {
            for(auto &node: e) {
                if(vertices.find(node) != vertices.end())
                    return node;
                else 
                    vertices.insert(node); 
            }
        }
        return -1;
    }
};