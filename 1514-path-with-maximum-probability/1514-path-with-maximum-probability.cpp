class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& probs, int start, int end) {
        vector<vector<pair<int, double>>> G(n);
        vector<double> maxi(n, (double)0.0);
        vector<bool> vis(n, 0);
        
        for(int i=0; i<edges.size(); i++) {
            G[edges[i][0]].push_back({edges[i][1], probs[i]});
            G[edges[i][1]].push_back({edges[i][0], probs[i]});
        }
        
        priority_queue<pair<double, int>> pq; pq.push({(double) 1.0, start});
        
        while(pq.size()) {
            auto i = pq.top(); pq.pop();
            if(!vis[i.second]) {
                vis[i.second] = true;
                for(auto &j: G[i.second]) {
                    if(maxi[j.first] < i.first * j.second) {
                        maxi[j.first] = i.first * j.second;
                        pq.push({maxi[j.first], j.first});
                    }
                }
            }
        }
        return maxi[end];
    }
};
