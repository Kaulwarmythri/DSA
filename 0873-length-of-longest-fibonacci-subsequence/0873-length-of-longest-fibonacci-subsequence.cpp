class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), maxi = 0;
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i=2; i<n; i++) {
            int l = 0, r = i-1;
            while(l < r) {
                int sum = arr[l] + arr[r];
                if(sum < arr[i]) l++;
                else if(sum > arr[i]) r--;
                else {
                    dp[r][i] = dp[l][r] + 1;
                    maxi = max(maxi, dp[r][i]);
                    l++; r--;
                }
            }
        }
        return maxi > 0 ? maxi + 2 : maxi;
    }
};