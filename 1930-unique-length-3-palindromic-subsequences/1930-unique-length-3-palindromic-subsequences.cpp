class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> min_indices(26, INT_MAX), max_indices(26, INT_MIN);
        
        for(int i=0; i<n; i++) {
            auto c = s[i] - 'a';
            min_indices[c] = min(min_indices[c], i);
            max_indices[c] = max(max_indices[c], i);
        }
        
        int ans = 0;   //num of palindromic subsequences of length 3
        
        for(int c=0; c<26; c++) {
            if(min_indices[c] == INT_MAX || max_indices[c] == INT_MIN)
                continue;
            
            unordered_set<char> uniques;
            
            for(int i=min_indices[c]+1; i<max_indices[c]; i++) 
                uniques.insert(s[i]);
            
            ans += uniques.size();
        }
        return ans;
    }
};