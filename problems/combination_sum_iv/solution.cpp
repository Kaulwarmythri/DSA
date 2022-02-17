class Solution {
public:
    vector<int> dp;
    int combinationSum4(vector<int>& nums, int X) {
        dp.resize(X+1, -1);
        dp[0] = 1;
        solve(nums, X);
        return dp[X];
    }
    int solve(vector<int> nums, int X){
        if(dp[X] != -1) return dp[X];
        int ans = 0;
        for(auto num : nums){
            if(num <= X) ans += solve(nums, X-num);
        }
        return dp[X] = ans;
    }
    
};


/* Recursive Solution for how to approach the above dp solution
class Solution {
public:
    int combinationSum4(vector<int>& nums, int X) {
        if(X == 0) return 1;
        int ans = 0;
        for(auto num : nums){
            if(num <= X) ans += combinationSum4(nums, X-num);
        }
        return ans;
    }
};
*/

