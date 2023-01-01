//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
        int n = s.size(), open = 0, close = 0, imbalance = 0, swaps = 0;
        
        for(int i=0; i<n; i++) {
            if(s[i] == '[') {
                open++;
                
                if(imbalance > 0) {
                    swaps += imbalance;
                    
                    imbalance--;
                } 
            } else {
                close++;
                
                imbalance = close - open;
            }
        }
        return swaps;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends