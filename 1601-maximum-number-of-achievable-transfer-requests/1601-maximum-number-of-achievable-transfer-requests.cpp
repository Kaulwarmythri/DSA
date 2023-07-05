class Solution {
    int m, ans = 0;
public:
    int maximumRequests(int n, vector<vector<int>>& A) {
        m = A.size();
        vector<int> indegree(n);
        
        solve(A, indegree, n, 0, 0);
        
        return ans;
    }
    
    void solve(vector<vector<int>> &A, vector<int> &I, int n, int start, int count) {
        if(start == m) {
            for(auto &i: I) 
                if(i != 0) return;
            
            ans = max(ans, count);
            return;
        }
        
        I[A[start][0]]--;
        I[A[start][1]]++;
        
        solve(A, I, n, start + 1, count + 1);
        
        I[A[start][0]]++;
        I[A[start][1]]--;
        
        solve(A, I, n, start + 1, count);
    }
};