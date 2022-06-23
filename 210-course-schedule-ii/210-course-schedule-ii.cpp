class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0), ans;
        
        for(auto node: p) {
            graph[node[1]].push_back(node[0]);
            indegree[node[0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++) 
            if(indegree[i] == 0) q.push(i);
        
        if(q.size() == 0) return vector<int>();
        
        while(q.size()) {
            int curr = q.front(); q.pop();
            ans.push_back(curr);
            
            for(auto nei: graph[curr]) {
                if(--indegree[nei] == 0) q.push(nei);
            }
        }
        return ans.size() == n ? ans : vector<int>();
    }
};