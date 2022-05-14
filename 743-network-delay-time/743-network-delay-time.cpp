class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int> > > g(n+1);
        
        for (auto e : times) {
            g[e[0]].push_back({e[2], e[1]});            
        }
        
        vector<int> dist(n+1, INT_MAX);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        dist[k] = 0;
        
        pq.push({0, k}); 
        
        while (!pq.empty()) {
            pair<int,int> x = pq.top(); pq.pop();
            
            for (auto n : g[x.second]) {
                int mini = dist[x.second] + n.first;
                if (mini < dist[n.second]) {
                    dist[n.second] = mini;
                    pq.push({mini, n.second});
                }
            }            
        }        
        int time = INT_MIN;
        for (int i = 1; i < dist.size(); ++i) {
            if (time < dist[i]) {
                time = dist[i];
            }
        }
        
        return time == INT_MAX ? -1 : time;
        
    }
};