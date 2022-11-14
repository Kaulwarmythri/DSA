class DSU {
public:
    vector<int> parent;
    int n;
    
    DSU(int n) {
        this->n = n;
        parent.resize(n, 0);
        for(int i=0; i<n; i++) parent[i] = i;
    }
    int find(int i) {
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    
    bool Unite(int x, int y) {
        x = find(x), y = find(y);
        if(x != y) parent[y] = x;
        else return false;
        
        return true;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& S) {
        int n = S.size(), count = 0;
        
        DSU *d = new DSU(n);
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if((S[i][0] == S[j][0]) || (S[i][1] == S[j][1])) 
                    if(d->Unite(i, j)) count++;
            }
        }
        return count;
    }
};