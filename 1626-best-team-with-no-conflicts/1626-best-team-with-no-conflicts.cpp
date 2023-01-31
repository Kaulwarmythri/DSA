class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<pair<int, int>> P(n, {0, 0});
        
        for(int i=0; i<n; i++) {
            P[i].first = ages[i];
            P[i].second = scores[i];
        }
        sort(P.begin(), P.end());
        
        vector<int> dp(n, 0);
        int ans = INT_MIN;
        for(int i=0; i<n; i++) {
            dp[i] = P[i].second;
            for(int j=i-1; j>=0; j--) {
                if(P[i].second >= P[j].second)
                    dp[i] = max(dp[i], dp[j] + P[i].second);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};