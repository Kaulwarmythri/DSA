class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size(), i = 0;
        vector<int> cntS(26, 0), cntP(26, 0), ans;
        
        if(m < n) return {};
        
        for(; i<n; i++) {
            cntS[s[i] - 'a']++;
            cntP[p[i] - 'a']++;
        }
        
        for(; i<m; i++) {
            if(cntS == cntP) ans.push_back(i - n);
            cntS[s[i - n] - 'a']--;
            cntS[s[i] - 'a']++;
        }
        if(cntS == cntP) ans.push_back(i - n);
        return ans;
    }
};