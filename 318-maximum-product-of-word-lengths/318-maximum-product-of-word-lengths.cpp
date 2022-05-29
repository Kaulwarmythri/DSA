class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), ans = INT_MIN;
        
        vector<int> masks(n, 0);
        
        for(int i=0; i<n; i++) {
            for(auto &ch : words[i]) {
                masks[i] |= 1 << (ch - 'a');
            }
            for(int j=0; j<i; j++) {
                if((masks[i] & masks[j]) == 0) 
                    ans = max(ans, int(words[i].size() * words[j].size())); 
            }
        }
        return ans > INT_MIN ? ans : 0;
    }
};