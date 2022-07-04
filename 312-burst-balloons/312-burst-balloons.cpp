class Solution {
    int n;
public:
    int maxCoins(vector<int>& nums) {
        vector<int> arr = {1};
        for(int x: nums) 
			arr.push_back(x);
        arr.push_back(1);
        n = arr.size();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return solve(arr, 1, n-2, dp);
    }
    
    int solve(vector<int> &nums, int i, int j, vector<vector<int>> &dp) {
        if(i > j)
			return 0;
        if(i == j) {    
            int temp = nums[i];
            if(i - 1 >= 0)  
                temp *= nums[i - 1];
            if(i + 1 < n)
                temp *= nums[i + 1];
            return temp;
        }
		if(dp[i][j] != -1)  return dp[i][j];
        
        int ans = 0;

        for(int k = i; k <= j; k++){
            int temp = nums[k];
			
            if(j + 1 < n)  temp *= nums[j + 1];
				
            if(i - 1 >= 0) temp *= nums[i - 1];
            
            temp += (solve(nums, i, k - 1, dp) + solve(nums, k + 1, j, dp));

            ans = max(ans, temp);
        }
        return dp[i][j] = ans;
    }
};