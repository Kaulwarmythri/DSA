class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> M(n, vector<int>(n));
        
        vector<int> count(n);
        int ans = INT_MAX;
        
        for(auto &e: edges) {
            M[min(e[0], e[1]) - 1][max(e[0], e[1]) - 1] = 1;
            
            count[e[0] - 1]++;
            count[e[1] - 1]++;
        }
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(M[i][j]) {
                    for(int k=j+1; k<n; k++) {
                        if(M[i][k] && M[j][k]) {
                            ans = min(ans, count[i] + count[j] + count[k] - 6);
                        }
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};