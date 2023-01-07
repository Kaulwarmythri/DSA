//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findNum(int n) {
        if(n == 1) return 5;
        int l = 0, r = 5 * n, ans;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(check(n, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    
    int check(int n, int mid) {
        int x = 5, temp = mid, countOfZeroes = 0;
        while(x <= temp) {
            countOfZeroes += temp / x;
            x *= 5;
        }
        return countOfZeroes >= n;
    }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends