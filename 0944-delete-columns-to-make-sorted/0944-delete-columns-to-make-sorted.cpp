class Solution {
public:
    int minDeletionSize(vector<string>& S) {
        int m = S.size(), n = S[0].size(), ans = 0;
        
        for(int j=0; j<n; j++) {
            for(int i=1; i<m; i++) {
                if(S[i][j] < S[i-1][j]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};