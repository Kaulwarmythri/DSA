//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{  
    int m, n;
    vector<int> lps, ans;
public:
    int findLastOccurence(string A,string B){
        m = A.size(), n = B.size();
        int i = 0, j = 0;
        lps.resize(n, 0);
        
        calc(B);
        
        while((m - i) >= (n - j)) {
            if(A[i] == B[j]) i++, j++;
            
            if(j == n) ans.push_back(i - j), j = lps[j-1];
            
            else if(A[i] != B[j]) {
                if(!j) i++;
                else j = lps[j-1];
            }
        }
        return ans.size() ? ans.back() + 1 : -1;
    }
    
    void calc(string s) {
        int i = 1, j = 0;
        while(i < n) {
            if(s[i] == s[j]) lps[i++] = ++j;
            else {
                if(!j) i++;
                else j = lps[j-1];
            }
        }
    } 
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends