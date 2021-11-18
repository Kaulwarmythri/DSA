class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint> dp(target+1, 0);
        dp[0]=1;
        for(int currentTarget=1;currentTarget<=target;currentTarget++){
            for(auto num : nums){
                if(num<=currentTarget) dp[currentTarget]+=dp[currentTarget-num];
            }
        }
        return dp[target];
    }
};