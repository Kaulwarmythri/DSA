//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int nums[], int n , int x ) {
    int l = 0, r = n-1;
    vector<int> ans(2, -1);
    
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(nums[mid] < x)
            l = mid + 1;
        else if(nums[mid] > x)
            r = mid - 1;
        else {
            ans[0] = mid;
            r = mid - 1;
        }
    }
    
    r = n - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(nums[mid] < x)
            l = mid + 1;
        else if(nums[mid] > x)
            r = mid - 1;
        else {
            ans[1] = mid;
            l = mid + 1;
        }
    }
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends