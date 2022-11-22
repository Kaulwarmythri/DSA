//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int findSum(int A[], int n) {
    	pair<int, int> ans = solve(A, n);
    	return ans.first + ans.second;
    }

    pair<int, int> solve(int A[], int n) {
        int mini = INT_MAX, maxi = INT_MIN, i = 0;
        if(n % 2) {
            if(A[0] < A[1]) mini = A[0], maxi = A[1];
            else mini = A[1], maxi = A[0];
            i = 2;
        } else {
            mini = A[0]; maxi = A[0];
            i = 1;
        }
        
        for(; i<n-1; i++) {
            if(A[i] > A[i+1]) {
                if(A[i] > maxi) maxi = A[i];
                if(A[i+1] < mini) mini = A[i+1]; 
            } else {
                if(A[i] < mini) mini = A[i];
                if(A[i+1] > maxi) maxi = A[i+1];
            }
        }
        return {mini, maxi};
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends