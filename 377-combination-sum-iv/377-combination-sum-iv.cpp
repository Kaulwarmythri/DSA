class Solution {
public:
    int combinationSum4(vector<int>& nums, int X) {
        vector<uint> dp(X+1, 0);
        dp[0] = 1;
        for(int curr=1; curr<=X; curr++){
            for(auto num : nums){
                if(num <= curr) dp[curr] += dp[curr-num];
            }
        }
        return dp[X];
    }
};