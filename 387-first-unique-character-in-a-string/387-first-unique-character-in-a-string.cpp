class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        int n = s.size();
        
        for(int i=0; i<n; i++) {
            if(m.find(s[i]) == m.end()) m[s[i]] = i;
            else m[s[i]] = n;
        }
        
        int minIdx = n;
        
        for(auto &x: m) {
            minIdx = min(minIdx, x.second);
        }
        return minIdx == n ? -1 : minIdx;
    }
};