class Solution {
public:
    int longestSubsequence(vector<int>& A, int diff) {
        int ans = 1;
        
        unordered_map<int, int> lens;
        
        for(auto &x: A) {
            if(lens.find(x - diff) != lens.end()) 
                lens[x] = lens[x - diff] + 1;
            else
                lens[x] = 1;
            
            ans = max(ans, lens[x]);
        }
        return ans;
    }
};