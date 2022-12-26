//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends

int check(int M[MAX][MAX], int mid, int n, int k) {
    int row = 0, col = n-1, count = 0;
    
    while(row < n && col >= 0) {
        if(M[row][col] <= mid) {
            count += col+1;
            row++;
        } else col--;
    }
    return count;
}

int kthSmallest(int M[MAX][MAX], int n, int k) {
    int l = M[0][0], r = M[n-1][n-1];
    
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(check(M, mid, n, k) < k) l = mid + 1;
        else r = mid;
    }
    return l;
}
