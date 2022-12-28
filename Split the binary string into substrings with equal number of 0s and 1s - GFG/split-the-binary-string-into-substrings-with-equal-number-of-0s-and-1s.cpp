//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string s) {
        int n = s.size(), ans = 0, zeroes = 0, ones = 0;
        
        for(int i=0; i<n; i++) {
            if(s[i] == '0') zeroes++;
            else ones++;
            
            if(zeroes == ones) ans++;
        }
        
        if(zeroes != ones) return -1;
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends