class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26);
        vector<string> ans;
        
        for(auto &w: words2) {
            vector<int> freq = countFreq(w);
            for(int i=0; i<26; i++) maxFreq[i] = max(maxFreq[i], freq[i]);
        }
        
        for(auto &w: words1) {
            vector<int> freq = countFreq(w);
            
            int i=0;
            for(; i<26; i++) if(freq[i] < maxFreq[i]) break;
            if(i == 26) ans.push_back(w);
        }
        return ans;
    }
    
    vector<int> countFreq(string word) {
        vector<int> freq(26, 0);
        
        for(auto &c: word) freq[c - 'a']++;
        
        return freq;
    }
};