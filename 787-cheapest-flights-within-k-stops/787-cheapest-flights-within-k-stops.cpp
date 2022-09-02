class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> G(n);
        
        for(auto &f: flights) {
            G[f[0]].push_back({f[1], f[2]});
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});
        
        vector<int> stops(n, INT_MAX);
        
        while(pq.size()) {
            auto curr = pq.top(); pq.pop();
            int price = curr[0], node = curr[1], numStops = curr[2];
            if(numStops > stops[node] || numStops > k+1)
                continue;
            
            stops[node] = numStops;
            if(node == dst)
                return price;
            for(auto &child: G[node]) {
                pq.push({price + child.second, child.first, numStops+1});
            }
        }
        return -1;
    }
};
