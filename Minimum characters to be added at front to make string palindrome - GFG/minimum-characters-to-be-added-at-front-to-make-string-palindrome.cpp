//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minChar(string s){
        int m = s.size();
        string x = s;
        reverse(x.begin(), x.end());
        
        s += '$' + x;
        int n = s.size();
        vector<int> lps(n, 0);
        
        int i = 1, j = 0;
        while(i < n) {
            if(s[i] == s[j]) lps[i++] = ++j;
            else {
                if(!j) i++;
                else j = lps[j-1];
            }
        }
        return m - lps[n-1];
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
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends