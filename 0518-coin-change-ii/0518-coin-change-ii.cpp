class Solution {
public:
    int change(int N, vector<int>& coins) {
        vector<int> dp(N+1, 0); dp[0] = 1;
        
        for(auto &c: coins) {
            for(int i=c; i<=N; i++) {
                dp[i] += dp[i - c];
            }
        }
        return dp[N];
    }
};


// in dp definition when you try to reduce the space complexity.If we define dp[i][j] as "number of ways to get sum 'j' using 'first i' coins", then the answer doesn't change because of loop arrangement.

// So why does the answer change only when we try to reduce the space complexity?

// To get the correct answer, the correct dp definition should be dp[i][j]="number of ways to get sum 'j' using 'first i' coins". Now when we try to traverse the 2-d array row-wise by keeping only previous row array(to reduce space complexity), we preserve the above dp definition as dp[j]="number of ways to get sum 'j' using 'previous /first i coins' " but when we try to traverse the 2-d array column-wise by keeping only the previous column, the meaning of dp array changes to dp[j]="number of ways to get sum 'j' using 'all' coins".