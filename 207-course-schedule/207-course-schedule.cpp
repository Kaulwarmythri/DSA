class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        int count = 0;
        if(pre.size() == 0) return true;
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        
        for(auto &node: pre) {
            graph[node[1]].push_back(node[0]);
            indegree[node[0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++) 
            if(indegree[i] == 0) q.push(i), indegree[i]--;
        
        if(q.size() == 0) return false;
        
        while(!q.empty()) {
            int s = q.size();
            for(int i=0; i<s; i++) {
                int curr = q.front(); q.pop();
                count++;
                
                for(auto neighbor: graph[curr]) {
                    indegree[neighbor]--;
                    if(indegree[neighbor] == 0) q.push(neighbor);
                }
            }
        }
        
        return count == n;
    }
};