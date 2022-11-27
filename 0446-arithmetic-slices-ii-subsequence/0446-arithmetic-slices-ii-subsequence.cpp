class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        
        vector<unordered_map<long, long>> dp(n);
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++) {
                long diff = (long)nums[i] - (long) nums[j];
                
                dp[i][diff]++;
                
                if(dp[j].find(diff) != dp[j].end()) {
                    dp[i][diff] += dp[j][diff];
                    
                    ans += dp[j][diff];
                }
            }
        }
        return ans;
    }
};
