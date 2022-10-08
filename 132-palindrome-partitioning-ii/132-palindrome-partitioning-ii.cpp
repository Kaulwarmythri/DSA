class Solution {
    vector<vector<int>> dp, pals;
public:
	bool isPalindrome(string &s, int i, int j) {
		if (i >= j) 
            return true;
		if (pals[i][j] != -1) 
            return pals[i][j];
		if (s[i] == s[j]) 
            return pals[i][j] = isPalindrome(s, i + 1, j - 1);
		return pals[i][j] = false;
	}

	int solve(string s, int i, int j){
		if(i >= j) 
            return dp[i][j] = 0;
		if(dp[i][j] != -1) 
            return dp[i][j];
		if(isPalindrome(s, i, j)) 
            return dp[i][j] = 0;
        
		int ans = INT_MAX;
		for(int k=i; k<j; k++){
			if(isPalindrome(s, i, k)) ans = min(ans, 1+solve(s, k+1, j));
		}
		return dp[i][j] = ans;
	}

	int minCut(string s) {
        int n = s.size();
		dp.resize(n, vector<int> (n, -1));
		pals.resize(n, vector<int>(n, -1));
                  
		return solve(s, 0, n-1);
	}
};

