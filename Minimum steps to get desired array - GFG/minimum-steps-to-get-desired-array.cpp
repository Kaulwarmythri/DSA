//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countMinOperations(int arr[], int n) {
        int ans = 0;
        
        while(true) {
            int zeroes = 0;
            int i = 0;
            
            for(i; i<n; i++) {
                if(!arr[i]) 
                    zeroes++;
                if(arr[i] & 1) 
                    break;
            }
            
            if(zeroes == n) return ans;
            if(i == n) {
                for(int j=0; j<n; j++) 
                    arr[j] = arr[j] / 2;
                ans++;
            }
            for(int j=i; j<n; j++) 
                if(arr[j] & 1) arr[j]--, ans++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countMinOperations(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends