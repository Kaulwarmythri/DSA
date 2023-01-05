//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int X) {
        if(nums.size() < 4) return {};
        
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        int n = nums.size(), i=0, j;
        
        for(i=0; i<n-1; i++){
            for(j=i+1; j<n; j++){
                int temp = X - nums[i]-nums[j], l = j+1, r = n-1;
                while(l < r){
                    if(nums[l]+nums[r] == temp) 
                        s.insert({nums[i], nums[j], nums[l], nums[r]}), l++, r--;
                    else if(nums[l]+nums[r] < temp) l++;
                    else r--;
                }
            }
        }
        return vector<vector<int>>(s.begin(), s.end());
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends