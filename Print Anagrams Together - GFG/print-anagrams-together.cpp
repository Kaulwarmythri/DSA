//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& A) {
        unordered_map<string, vector<string>> m;
        
        for(auto &s: A) {
            m[count_sort(s)].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto &x: m) {
            ans.push_back(x.second);
        }
        return ans;
    }
    
    string count_sort(string s) {
        string t;
        vector<int> cnt(26, 0);
        
        for(auto &c: s) cnt[c - 'a']++;
        
        for(int i=0; i<26; i++) {
            int k = cnt[i];
            while(k--) {
                t += 'a' + i;
            }
        }
        return t;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends