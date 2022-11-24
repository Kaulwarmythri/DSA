class Solution {
    int n;
    vector<int> dp;
public:
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        dp.resize(n+1, -1);
        
        int ans = INT_MIN;
        for(int i=0; i<n; i++) {
            ans = max(ans, 1+solve(arr, i, d));
        }
        return ans;
    }
    int solve(vector<int> &arr, int i, int d) {
        if(dp[i] != -1) return dp[i];
        
        dp[i] = 0;
        for(int j=i-1; j>=0 && arr[i] > arr[j] && j >= i-d; j--) {
            dp[i] = max(dp[i], 1 + solve(arr, j, d));
        }
        
        for(int j=i+1; j<n && arr[i] > arr[j] && j <= i+d; j++) {
            dp[i] = max(dp[i], 1 + solve(arr, j, d));
        }
        return dp[i];
    } 
};