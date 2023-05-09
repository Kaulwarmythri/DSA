class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        vector<int> ans;
        int m = A.size() - 1, n = A[0].size() - 1, i = 0, j = 0;
        
        while(i <= m && j <= n) {
            for(int k=j; k<=n; k++)
                ans.push_back(A[i][k]);
            i++;
            
            for(int l=i; l<=m; l++)
                ans.push_back(A[l][n]);
            n--;
            
            if(i <= m) {
                for(int k=n; k>=j; k--)
                    ans.push_back(A[m][k]);
                m--;
            }
            
            if(j <= n) {
                for(int l=m; l>=i; l--)
                    ans.push_back(A[l][j]);
                j++;
            }
        }
        return ans;
    }
};
