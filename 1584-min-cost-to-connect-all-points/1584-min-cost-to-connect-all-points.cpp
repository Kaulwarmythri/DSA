class Solution {
    vector<int> parent, rank;
    
    int find(int i) {
        if(parent[i] == -1) return i;
        
        return parent[i] = find(parent[i]); 
    }
    
    void unite(int x, int y) {
        int xRep = find(x);
        int yRep = find(y);
        
        if(xRep != yRep) {
            if(rank[x] > rank[y]) {
                parent[x] = yRep;
                rank[y] += rank[x];
            }
            else {
                parent[y] = xRep;
            }
            rank[x] += rank[y];
        }
    }
    
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n = p.size();
        
        parent.resize(n, -1);
        rank.resize(n, 1);
        
        vector<pair<int, pair<int, int>>> g;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int weight = abs(p[i][0] - p[j][0]) + 
                             abs(p[i][1] - p[j][1]);
                
                g.push_back({weight, {i, j}});
                
            }
        }

        sort(g.begin(), g.end());
        
        int ans = 0; //intially define sum as zero
        
        // for each edge we travel
        for(auto e: g) {
            int a = find(e.second.first); // first node
            int b = find(e.second.second); // second node
            
            if(a != b) {
                ans += e.first;
                unite(a, b); // now merge them
            }
        }
        
        return ans;
    }
};