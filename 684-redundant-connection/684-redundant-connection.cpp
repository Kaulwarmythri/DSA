class DSU {
public:
    int n;
    vector<int> parent, rank;
    
    DSU(int n) {
        this->n = n;
        parent.resize(n);
        rank.resize(n, 0);
        
        for(int i=0; i<n; i++) parent[i] = i;
    }
    
    int find(int i) {
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    
    bool Union(int x, int y) {
        int xrep = find(x), yrep = find(y);
        if(xrep == yrep)
            return false;
        if(rank[xrep] >= rank[yrep])
            parent[yrep] = xrep;
        else 
            parent[xrep] = yrep;
        
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU *dsu = new DSU(n+1);
        
        for(auto &e: edges) {
            if(!dsu->Union(e[0], e[1]))
                return e;
        }
        return {};
    }
};