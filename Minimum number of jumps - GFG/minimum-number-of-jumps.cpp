//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n) {
        int curr_reach = 0, max_reach = 0, jumps = 0;
        
        for(int i=0; i<n-1; i++) {
            max_reach = max(max_reach, arr[i] + i);
            
            if(curr_reach == i) {
                curr_reach = max_reach;
                jumps++;
            }
        }
        if(curr_reach < n-1) return -1;
        return jumps;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends