class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        string p = normalize(pattern);
        
        for(auto &w: words) {
            if(normalize(w) == p) ans.push_back(w); 
        }
        return ans;
    }
    
    string normalize(string s) {
        char c = 'a';
        unordered_map<char, char> m;
        
        for(auto &ch: s) {
            if(!m.count(ch)) m[ch] = c++;   
        }
        
        for(auto &ch: s) ch = m[ch];
        return s;
    }
};