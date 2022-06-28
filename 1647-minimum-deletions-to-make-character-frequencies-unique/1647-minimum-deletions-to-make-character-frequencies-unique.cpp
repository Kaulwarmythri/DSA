class Solution {
public:
    int minDeletions(string s) {
        int ans = 0;
        vector<int> freq(26, 0);
        unordered_set<int> used;
        
        for(auto &c: s) freq[c - 'a']++;
        
        for(int i=0; i<26; i++) {
            while(freq[i] > 0 && used.find(freq[i]) != used.end()) freq[i]--, ans++;
            used.insert(freq[i]);
        }
        
        return ans;
    }
};