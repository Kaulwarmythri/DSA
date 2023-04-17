class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& A, int extra) {
        int n = A.size(), maxi = *max_element(A.begin(), A.end());
        
        vector<bool> ans(n);
        for(int i=0; i<n; i++) {
            if(A[i] + extra >= maxi) ans[i] = true;
        }
        return ans;
    }
};