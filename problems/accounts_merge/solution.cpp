class UnionFind{
public:
    unordered_map<string, string> root;
    unordered_map<string, int> rank;
    
    string find(string s){
        if(!root.count(s)) root[s] = s, rank[s]=1;
        if(root[s] != s) root[s] = find(root[s]);
        
        return root[s];
    }
    void Union(string x, string y){
        string x_rep = find(x), y_rep = find(y);
        if(x_rep == y_rep) return;
        if(rank[x_rep] > rank[y_rep]) swap(x_rep, y_rep); //The idea is to always connect x's children to y_rep
        root[x_rep] = y_rep;
        rank[y_rep] += rank[x_rep];
        return;
        
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        UnionFind *uf = new UnionFind();
        
        unordered_map<string, string> owner;
        for(auto account : accounts){
            for(int i=1;i<account.size();i++){
                owner[account[i]] = account[0];
                uf->Union(account[i], account[1]);
            }
        }
        unordered_map<string, set<string>> m;
        for(auto account : accounts){
            for(int i=1;i<account.size();i++){
                m[uf->find(account[i])].insert(account[i]);
            }
        }
        
        for(auto a : m){
            vector<string> v(a.second.begin(), a.second.end());
            v.insert(v.begin(), owner[a.first]);
            ans.push_back(v);
        }
        delete uf;
        return ans;
        
    }
};