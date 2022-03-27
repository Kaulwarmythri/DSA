class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        
        set<pair<int, int>> s;
        
        for(int i=0; i<m; i++){
            s.insert({count(mat[i].begin(), mat[i].end(), 1), i});
        }
        
        vector<int> ans;
        
        for(auto x : s){
            if(k == 0) break;
            ans.push_back(x.second);
            
            k--;
        }
        return ans;
    }
};