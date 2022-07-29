class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string> ans;
        
        unordered_map<char, char> m; 
        bool visited[26] = {0};
        
        for(auto &w: words) {
            if(w.size() != p.size()) continue;
            if(match(w, p)) ans.push_back(w);
        }
        
        return ans;
    }
    
    bool match(string w1, string w2) {
        unordered_map<char, char> m;
        bool visited[26] = {0};
        
        for(int i=0; i<w1.size(); i++) {
            if((m[w1[i]] && m[w1[i]] != w2[i]) || (!m[w1[i]] && visited[w2[i] - 'a']))                      return false;
            
            m[w1[i]] = w2[i];
            visited[w2[i] - 'a'] = true;
        }
        return true;
    }
};