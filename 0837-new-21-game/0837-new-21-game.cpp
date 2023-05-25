class Solution {
public:
    double new21Game(int n, int k, int maxi) {
        if(k == 0 || n >= k + maxi) 
            return 1;
        
        vector<double> dp(n+1); dp[0] = 1.0;
        double Wsum = 1.0, ans = 0.0;
        
        for(int i=1; i<=n; i++) {
            dp[i] = Wsum * 1 / maxi;
            if(i < k) 
                Wsum += dp[i];
            else
                ans += dp[i];
            
            if(i - maxi >= 0) Wsum -= dp[i-maxi];
        }
        return ans;
    }
};