class Solution {
public:
    bool isAlienSorted(vector<string>& W, string O) {
        int n = W.size();
        
        vector<int> m(26, 0);
        
        for(int i=0; i<26; i++) {
            m[O[i] - 'a'] = i;
        }
        
        for(auto &w: W) {
            for(auto &c: w) {
                c = m[c - 'a'];
            }
        }
        return is_sorted(W.begin(), W.end());
    }
};