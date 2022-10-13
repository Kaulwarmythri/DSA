//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:	
	bool hasArrayTwoCandidates(int a[], int n, int x) {
	    int i, rem[x];
        for (i = 0; i < x; i++) rem[i] = 0;
        for (i = 0; i < n; i++)
            if (a[i] < x) rem[a[i] % x]++;
     
        for (i = 1; i < x / 2; i++) {
            if (rem[i] > 0 && rem[x - i] > 0) {
                return true;
                break;
            }
        }
        if (i >= x / 2) {
            if (x % 2 == 0) {
                if (rem[x / 2] > 1) return true;
                else return false;
            }
            else {
                if (rem[x / 2] > 0 && rem[x - x / 2] > 0) return true;
                else return false;
            }
        }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}

// } Driver Code Ends