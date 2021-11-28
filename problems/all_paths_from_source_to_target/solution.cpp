class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> currPath;
        solve(graph, currPath, 0);
        
        return ans;
    }
    
    void solve(vector<vector<int>> &graph, vector<int> &path, int i){
        path.push_back(i);
        if(i==graph.size()-1) ans.push_back(path);
        
        for(auto adj : graph[i]) solve(graph, path, adj); 
        
        path.pop_back();
    }
};
