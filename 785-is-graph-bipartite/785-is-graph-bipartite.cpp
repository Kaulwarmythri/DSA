class Solution {
public:
    bool isBipartite(vector<vector<int>>& G) {
        int n = G.size(); 
        vector<int> C(n, 0);
        
        queue<int> q; 
        
        for(int i=0; i<n; i++) {
            if(C[i]) 
                continue;
            C[i] = 1;
            q.push(i);
            while(!q.empty()) {
                auto curr = q.front(); q.pop();
                for(auto &adj: G[curr]) {
                    if(!C[adj]) {
                        C[adj] = -C[curr];
                        q.push(adj);
                    }
                    else if(C[adj] == C[curr])
                        return false;
                }
            }
        }
        return true;
    }
};