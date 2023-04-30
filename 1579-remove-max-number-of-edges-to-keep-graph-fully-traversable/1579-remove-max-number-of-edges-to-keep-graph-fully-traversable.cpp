class DSU {
 public:
    int n;
    vector<int> parent;
    
    DSU(int n) {
        this->n = n;
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int i) {
        return parent[i] == i ? i : parent[i] = find(parent[i]);
    }
    
    bool Union(int x, int y) {
        x = find(x), y = find(y);
        
        if(x == y) return false;
        
        parent[y] = x;
        n--;
        
        return true;   
    }
    
    bool connected() {
        return n == 1;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& E) {
        int ans = 0;
        DSU A(n), B(n);
        
        sort(E.begin(), E.end(), [](auto &a, auto &b) {
            return a[0] > b[0];
        });
        
        for(auto &e: E) {
            int type = e[0], u = e[1], v = e[2];
            switch(type) {
                case 3:
                    ans += A.Union(u, v) && B.Union(u, v);
                    break;
                case 2:
                    ans += B.Union(u, v);
                    break;
                case 1:
                    ans += A.Union(u, v);
                    break;
            }
        }
        return A.connected() && B.connected() ? E.size() - ans : -1;
    }
};