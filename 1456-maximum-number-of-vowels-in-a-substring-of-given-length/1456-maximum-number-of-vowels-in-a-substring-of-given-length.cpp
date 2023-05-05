class Solution {
    int vowels[26] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
public:
    int maxVowels(string s, int k) {
        int n = s.size(), maxi = 0, cur = 0, i = 0;
        
        while(i < n) {
            cur += vowels[s[i] - 'a'];
            
            if(i >= k) cur -= vowels[s[i - k] - 'a'];
            
            maxi = max(maxi, cur);
            i++;
        }
        return maxi;
    }
};