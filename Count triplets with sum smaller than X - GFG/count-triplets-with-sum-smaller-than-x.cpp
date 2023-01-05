//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
	long long countTriplets(long long nums[], int n, long long x) {
	    long long ans = 0;
	    if(n < 3) return ans;
	    
	    sort(nums, nums+n);
	    
	    for(int i=0; i<n; i++) {
	        int l = i+1, r = n-1;
	        while(l < r) {
	            int sum = nums[i] + nums[l] + nums[r];
	            if(sum < x) {
	                ans += r-l;
	                l++;
	            } else r--;
	        }
	    }
	    return ans;
	}
		 

};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends