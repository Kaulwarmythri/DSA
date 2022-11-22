//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int findSum(int A[], int n) {
    	pair<int, int> ans = solve(A, 0, n-1);
    	return ans.first + ans.second;
    }

    pair<int, int> solve(int A[], int l, int r) {
        if(l == r) 
            return {A[l], A[l]};
        
        if(r == l+1) 
            if(A[l] < A[r]) return {A[l], A[r]};
            else return {A[r], A[l]};
            
        int mid = l + (r - l) / 2, mini, maxi;
        pair<int, int> left = solve(A, l, mid), right = solve(A, mid+1, r);
        if(left.first < right.first) mini = left.first;
        else mini = right.first;
        
        if(left.second > right.second) maxi = left.second;
        else maxi = right.second;
        
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