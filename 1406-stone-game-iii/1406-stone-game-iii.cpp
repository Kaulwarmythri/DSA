class Solution {
    int n;
    vector<int> dp;
public:
    string stoneGameIII(vector<int>& A) {
        n = A.size();
        dp.resize(n, -1);
        
        int ans = maxDiff(A, 0);
        return ans == 0 ? "Tie" : ans > 0 ? "Alice" : "Bob";
    }
    
    int maxDiff(vector<int> &A, int i) {
        if(i >= n) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int ans = INT_MIN, total = 0;
        for(int j=0; j<3; j++) {
            if(i + j < n) total += A[i+j];
            ans = max(ans, total - maxDiff(A, i+j+1));
        }
        return dp[i] = ans;
    }
};