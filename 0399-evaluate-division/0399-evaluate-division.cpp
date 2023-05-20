class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eqns, vector<double>& vals, vector<vector<string>>& qs) {
        vector<double> ans;
        unordered_map<string, double> mp;
        unordered_map<string, vector<string>> graph;
        
        for(int i=0; i<eqns.size(); i++) {
            string u = eqns[i][0], v = eqns[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            mp[u+"->"+v] = vals[i];
            mp[v+"->"+u] = 1/vals[i];
        }
        
        for(int i=0; i<qs.size(); i++) {
            string s = qs[i][0], e = qs[i][1];
            if(graph.find(s) == graph.end() || graph.find(e) == graph.end())
                ans.push_back(-1);
            else {
                bool found = false;
                double val = 1;
                map<string, bool> vis;
                
                if(s == e)
                    found = true;
                else 
                    dfs(s, e, mp, graph, found, val, vis);
                if(found)
                    ans.push_back(val);
                else 
                    ans.push_back(-1);        
            }
        }
        return ans;
    }
    
    void dfs(string curr, string end, unordered_map<string, double> mp, unordered_map<string, vector<string>> graph, bool &found, double &val, map<string, bool> &vis) {
        vis[curr] = true;
        
        if(found)
            return;
        
        for(auto &child: graph[curr]) {
            if(!vis[child]) {
                val *= mp[curr+"->"+child];
                if(end == child) {
                    found = true;
                    return;
                }
                dfs(child, end, mp, graph, found, val, vis);
                if(found)
                    return;
                else 
                    val /= mp[curr+"->"+child];
            }
            
        }
        
        
    }
};