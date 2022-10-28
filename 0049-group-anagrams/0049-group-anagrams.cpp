class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        
        for(auto &s: strs) {
            m[countSort(s)].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto &x: m) {
            ans.push_back(x.second);
        }
        return ans;
    }
    
    string countSort(string s) {
        string t;
        vector<int> cnt(26, 0);
        
        for(auto &c: s) cnt[c - 'a']++;
        
        for(int i=0; i<26; i++) {
            int k = cnt[i];
            while(k--) {
                t += 'a' + i;
            }
        }
        return t;
    }
};