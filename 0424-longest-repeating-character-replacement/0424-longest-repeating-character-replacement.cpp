class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), l = 0, r = 0, max_curr_f = 0, ans = 0;
        
        vector<int> counts(26, 0);
        while(r < n) {
            counts[s[r] - 'A']++;
            max_curr_f = max(max_curr_f, counts[s[r] - 'A']);
            
            while(r - l + 1 - max_curr_f > k) {
                counts[s[l++] - 'A']--;
                max_curr_f = *max_element(counts.begin(), counts.end());
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};