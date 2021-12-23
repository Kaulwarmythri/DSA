class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0), ans;
        
        for(auto x : p){
            graph[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0) q.push(i);
        }
        
        while(q.size()){
            int curr = q.front(); q.pop();
            ans.push_back(curr);
            
            for(auto child : graph[curr]){
                if(--indegree[child] == 0) q.push(child);
            }
        }
        
        return ans.size() == n ? ans : vector<int>();
    }
};