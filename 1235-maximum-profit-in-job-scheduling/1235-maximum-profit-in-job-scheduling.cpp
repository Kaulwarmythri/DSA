class Solution {
    map<int, int> dp;
    int n;
public:
    int jobScheduling(vector<int>& S, vector<int>& E, vector<int>& P) {
        n = S.size();
        vector<vector<int>> jobs;
        
        for(int i=0; i<n; i++) {
            jobs.push_back({S[i], E[i], P[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        return solve(jobs, 0);
    }
    
    int solve(vector<vector<int>> &jobs, int curr) {
        if(curr == n) return 0;
        
        if(dp.find(curr) != dp.end()) return dp[curr];
        
        int next = findNext(jobs, curr), inc = jobs[curr][2] + (next == -1 ? 0 : solve(jobs, next)), exc = solve(jobs, curr+1);
        
        return dp[curr] = max(inc, exc); 
    }
    
    int findNext(vector<vector<int>> &jobs, int curr) {
        for(int next = curr+1; next < n; next++) {
            if(jobs[next][0] >= jobs[curr][1])
                return next;
        }
        return -1;
    }
};