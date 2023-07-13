class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& P) {
        vector<vector<int>> G(n);
        vector<int> indegree(n, 0);
        
        for(auto &p: P) {
            G[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++) 
            if(indegree[i] == 0) 
                q.push(i);
        
        if(q.empty())
            return false;
        
        while(q.size()) {
            auto cur = q.front(); q.pop();
            
            for(auto &node: G[cur]) {
                if(--indegree[node] == 0) q.push(node);
            }
            n--;
        }
        return n == 0;
    }
};