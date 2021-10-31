class Solution {
public:
    int help(vector<int>nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int>dp(n+1,0);
        dp[0] = 0;
        dp[1] = nums[0];
        dp[2] = nums[1];
        for (int i=3;i<=n;i++) 
            dp[i]=nums[i-1]+max(dp[i-2],dp[i-3]);
        return max(dp[n],dp[n-1]);
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        return max(help(vector<int>(nums.begin(),nums.end()-1)),help(vector<int>(nums.begin()+1,nums.end())));
        
    }
};