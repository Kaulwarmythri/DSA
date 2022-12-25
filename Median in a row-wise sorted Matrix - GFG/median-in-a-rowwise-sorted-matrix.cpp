//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &M, int m, int n){
        int l = INT_MAX, r = INT_MIN;
        
        for(int i=0; i<m; i++) l = min(l, M[i][0]), r = max(r, M[i][n-1]);
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(check(M, mid, m, n)) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
    
    int check(vector<vector<int>> &M, int mid, int m, int n) {
        int count = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(M[i][j] <= mid) count++;
                else break;
            }
        }
        return count <= m * n / 2;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends