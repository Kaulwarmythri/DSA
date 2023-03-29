class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, INT_MAX);
        dp[0] = 0;
        int j = 0;
        for (int i = 1; i < dp.size(); i++) {
            if(i > days.back()) break;
            if (j >= days.size() || i != days[j]) { 
                dp[i] = dp[i - 1]; 
                continue; 
            }
            dp[i] = min({dp[i], (i >= 1 ? dp[i-1] : 0) + costs[0], (i >= 7 ? dp[i-7] : 0) + costs[1], (i >= 30 ? dp[i-30] : 0) + costs[2]});
            j++;
        }

        return dp[days.back()];
    }
};

 
