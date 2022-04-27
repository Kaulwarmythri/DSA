class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<vector<int>> g(n);
        
        vector<bool> seen(n, false);
        
        for(auto &p : pairs) {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        
        for(int i=0; i<n; i++) {
            if(!seen[i]) {
                vector<int> pos;
                vector<char> chars;
                
                dfs(i, g, seen, pos, chars, s);
                
                sort(pos.begin(), pos.end());
                sort(chars.begin(), chars.end());
                
                int m = pos.size();
                for(int j=0; j<m; j++) s[pos[j]] = chars[j];
            }
        }
        return s;
    }
    
    void dfs(int i, vector<vector<int>> &g, vector<bool> &seen, vector<int> &pos, vector<char> &chars, string &s) {
        seen[i] = true;
        pos.push_back(i);
        chars.push_back(s[i]);
        
        for(auto &n : g[i]) {
            if(!seen[n]) dfs(n, g, seen, pos, chars, s);
        }
    }
};