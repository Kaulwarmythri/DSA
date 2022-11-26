class Solution {
    unordered_map<int, int> dp;
    vector<vector<int>> jobs;
    int n;
public:
    int jobScheduling(vector<int>& S, vector<int>& E, vector<int>& P) {
        n = S.size();
        
        
        for(int i=0; i<n; i++) {
            jobs.push_back({S[i], E[i], P[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        return solve(0);
    }
    
    int solve(int curr) {
        if(curr == n) return 0;
        
        if(dp.find(curr) != dp.end()) return dp[curr];
        
        int next = findNext(curr), inc = jobs[curr][2] + (next == -1 ? 0 : solve(next)), exc = solve(curr+1);
        
        return dp[curr] = max(inc, exc); 
    }
    
    int findNext(int curr) {
        for(int next = curr+1; next < n; next++) {
            if(jobs[next][0] >= jobs[curr][1])
                return next;
        }
        return -1;
    }
};