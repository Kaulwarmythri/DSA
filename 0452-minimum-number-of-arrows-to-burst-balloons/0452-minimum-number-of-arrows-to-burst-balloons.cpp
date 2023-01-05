class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& P) {
        int n = P.size(), ans = 1, prev = -1;
        if(n == 1) return ans;
        
        sort(P.begin(), P.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        
        prev = P[0][1];
        for(int i=1; i<n; i++) {
            if(P[i][0] <= prev) continue;
            
            ans++;
            prev = P[i][1];
        }
        return ans;
    }
};