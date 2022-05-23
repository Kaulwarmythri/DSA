class Solution {
    int size;
    int dp[601][101][101];
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        size = strs.size();
        vector<pair<int, int>> pairs;
        memset(dp, -1, sizeof(dp));
        
        for(auto &s : strs) {
            int zeroes = count(s.begin(), s.end(), '0'), ones = s.size() - zeroes;
            pairs.push_back({zeroes, ones});
        }
        return solve(pairs, 0, m, n);
    }
    
    int solve(vector<pair<int, int>> &pairs, int idx, int m, int n) {
        if(idx == size || (m == 0 && n == 0)) return 0;
        
        if(dp[idx][m][n] != -1) return dp[idx][m][n];
        
        if(pairs[idx].first > m || pairs[idx].second > n) 
            return dp[idx][m][n] = solve(pairs, idx+1, m, n);
        
        int include = 1 + solve(pairs, idx+1, m-pairs[idx].first, n-pairs[idx].second), 
        exclude = solve(pairs, idx+1, m, n);
        
        return dp[idx][m][n] = max(include, exclude);
    }
};