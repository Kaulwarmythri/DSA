class Solution {
public:
    bool canPlaceFlowers(vector<int>& A, int n) {
        int m = A.size(), ans = 0;
        
        for(int i=0; i<m; i++) {
            if(A[i] == 0 && (i == 0 || A[i-1] != 1) && (i == m-1 || A[i+1] != 1)) {
                ans++;
                A[i] = 1;
            }
        }
        return ans >= n ? true : false;
    }
};