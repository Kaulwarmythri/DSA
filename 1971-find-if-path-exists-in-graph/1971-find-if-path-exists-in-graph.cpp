class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<vector<int>> graph(n);
        vector<bool> vis(n, false);
        
        for(auto &e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        return dfs(graph, vis, s, d);
    }
    
    bool dfs(vector<vector<int>> &graph, vector<bool> &vis, int curr, int dest) {
        if(curr == dest) 
            return true;
        if(vis[curr]) 
            return false;
        
        vis[curr] = true;
        
        for(int i=0; i<graph[curr].size(); i++) {
            if(dfs(graph, vis, graph[curr][i], dest)) 
                return true;
        }
        return false;
        
    }
};