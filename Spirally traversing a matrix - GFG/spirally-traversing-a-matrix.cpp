//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> &M, int m, int n) {
        vector<int> ans;
        
        int i = 0, j = 0;
        
        while(i < m && j < n) {
            for(int k=j; k<n; k++) ans.push_back(M[i][k]);
            i++;
            
            for(int l=i; l<m; l++) ans.push_back(M[l][n-1]);
            n--;
            
            if(i < m) {
                for(int k=n-1; k>=j; k--) ans.push_back(M[m-1][k]);
                m--;
            }
            
            if(j < n) {
                for(int l=m-1; l>=i; l--) ans.push_back(M[l][j]);
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends