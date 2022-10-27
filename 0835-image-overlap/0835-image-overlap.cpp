class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        vector<pair<int, int>> A1, B1;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(A[i][j] == 1) A1.push_back({i, j});
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(B[i][j] == 1) B1.push_back({i, j});
            }
        }
        
        map<pair<int, int>, int> counts;
        
        for(auto &[i1, j1]: A1) {
            for(auto &[i2, j2]: B1) {
                counts[{i1 - i2, j1 - j2}]++;
            }
        }
        int ans = 0;
        for(auto &x: counts) {
            ans = max(ans, x.second);
        }
        return ans;     
    }
};
