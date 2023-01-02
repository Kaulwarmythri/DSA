//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string s) {
        unordered_map<char, int> m;
        for(auto &c: s) 
            m[c] = 0;
        
        int n = s.size(), l = 0, r = 0, count = 0, size = m.size(), min_len = n;
        
        for(; r<n; r++) {
            m[s[r]]++;
            if(m[s[r]] == 1) count++;
            
            while(count == size && l <= r) {
                min_len = min(min_len, r - l + 1);
                m[s[l]]--;
                if(m[s[l]] == 0) count--;
                l++;
            }
        }
        return min_len;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends