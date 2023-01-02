//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution {
public:
    bool areIsomorphic(string s, string t) {
        return normalise(s) == normalise(t);
    }
    
    string normalise(string s) {
        char curr = 'A';
        unordered_map<char, char> m;
        for(auto &c: s) if(!m[c]) m[c] = curr++;
        
        for(auto &c: s) {
            c = m[c];
        }
        return s;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends