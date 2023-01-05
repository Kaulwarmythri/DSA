//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       vector<long long int> ans(n, 1);
       long long left = 1, right = 1;
       
       for(int i=0; i<n; i++) {
           ans[i] *= left;
           left *= nums[i];
           ans[n - i - 1] *= right;
           right *= nums[n - i - 1];
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends