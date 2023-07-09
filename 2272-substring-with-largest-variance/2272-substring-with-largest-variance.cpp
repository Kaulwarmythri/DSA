class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        
        for(char c1 = 'a'; c1 <= 'z'; c1++) {
            for(char c2 = 'a'; c2 <= 'z'; c2++) {
                if(c1 == c2) continue;
                int low_freq = 0, high_freq = 0, low_freq_abandoned = false;
                
                for(auto &c: s) {
                    if(c == c1) high_freq++;
                    else if(c == c2) low_freq++;
                    
                    if(low_freq > 0) 
                        ans = max(ans, high_freq - low_freq);
                    else {
                        if(low_freq_abandoned) 
                            ans = max(ans, high_freq - 1);
                    }
                    
                    if(low_freq > high_freq) {
                        high_freq = low_freq = 0;
                        low_freq_abandoned = true;
                    }
                }
            }
        }
        return ans;
    }
};