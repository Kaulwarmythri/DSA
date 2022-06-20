class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        
        return max(solve(vector<int>(nums.begin(), nums.end()-1)), solve(vector<int>(nums.begin()+1, nums.end())));
    }
    
    int solve(vector<int> a) {
        int n = a.size();
        
        if(n==1) return a[0];
        vector<int> dp(n, 0);
        dp[0] = a[0];
        dp[1] = max(a[1], a[0]);
        
        for(int i=2; i<n; i++) {
            dp[i] = max(dp[i-1], a[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};