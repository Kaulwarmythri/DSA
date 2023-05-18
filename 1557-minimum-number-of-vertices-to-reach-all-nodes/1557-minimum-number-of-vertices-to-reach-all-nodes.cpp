class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& E) {
        vector<int> inorder(n, 0), ans;
        
        for(auto &e: E) 
            inorder[e[1]]++;
        
        for(int i=0; i<n; i++) 
            if(!inorder[i]) ans.push_back(i);
        
        return ans;
    }
};