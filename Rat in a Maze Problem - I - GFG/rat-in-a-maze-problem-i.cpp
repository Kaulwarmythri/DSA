//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    vector<string> ans;
    int N;
public:
    vector<string> findPath(vector<vector<int>> &M, int n) {
        if(M[0][0] == 0 || M[n-1][n-1] == 0) return {};
        N = n;
        string curr = "";
        solve(M, 0, 0, curr);
        
        return ans;
    }
    
    void solve(vector<vector<int>> &M, int i, int j, string curr) {
        if(i == N-1 && j == N-1) {
            ans.push_back(curr);
            return;
        }
        
        M[i][j] = 2;
        if(isValid(M, i-1, j))
            solve(M, i-1, j, curr+'U');
        if(isValid(M, i, j-1))
            solve(M, i, j-1, curr+'L');
        if(isValid(M, i+1, j))
            solve(M, i+1, j, curr+'D');
        if(isValid(M, i, j+1))
            solve(M, i, j+1, curr+'R');
            
        M[i][j] = 1;
    }
    
    bool isValid(vector<vector<int>> &M, int i, int j) {
        if(i < 0 || j < 0 || i >= N || j >= N || M[i][j] != 1)
            return false;
        return true;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends