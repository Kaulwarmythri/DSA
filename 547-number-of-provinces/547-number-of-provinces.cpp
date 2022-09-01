class DSU {
public:
    int n;
    vector<int> parent, rank;
    
    DSU(int n) {
        this->n = n;
        parent.resize(n);
        
        for(int i=0; i<parent.size(); i++)
            parent[i] = i;
        
        rank.resize(n, 0);
    }
    
    int find(int i) {
        if(parent[i] == i) 
            return i;
        return parent[i] = find(parent[i]);
    }
    
    void unite(int x, int y) {
        int xrep = find(x), yrep = find(y);
        
        if(rank[xrep] >= rank[yrep])
            parent[yrep] = xrep;
        else 
            parent[xrep] = yrep;
    }
    
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& G) {
        int n = G.size();
        DSU *dsu = new DSU(n);
        
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(G[i][j])
                    dsu->unite(i, j);
            }
        }
        
        unordered_map<int, int> m;
        int count = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(G[i][j]) {
                    if(dsu->find(i) == dsu->find(j) && m.find(dsu->find(i)) == m.end()) {
                        count++;
                        m[dsu->find(i)] = 1;
                    }
                }
                    
            }
        }
        return count;
    }
};