//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    string smallestWindow (string s, string t) {
        int m = s.size(), n = t.size(), l = 0, r = 0, count = 0, min_len = INT_MAX, start = -1;
        
        unordered_map<char, int> mp;
        for(auto &c: t) mp[c]++;
        
        for(r; r<m; r++) {
            if(mp[s[r]] > 0) count++;
            mp[s[r]]--;
            
            if(count == n) {
                while(l < r && mp[s[l]] < 0) mp[s[l++]]++;
                if(min_len > r - l + 1) min_len = r - (start = l) + 1;
                mp[s[l++]]++;
                count--;
            }
        }
        return min_len == INT_MAX ? "-1" : s.substr(start, min_len);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends