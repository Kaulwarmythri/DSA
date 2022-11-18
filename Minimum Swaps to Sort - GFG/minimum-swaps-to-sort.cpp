//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int minSwaps(vector<int>&nums) {
        int n = nums.size();
	    vector<pair<int, int>> a(n);
	    
	    for(int i=0; i<n; i++) {
	        a[i].first = nums[i];
	        a[i].second = i;
	    }
	    
	    sort(a.begin(), a.end());
	    
	    vector<bool> vis(n, false);
	    int ans = 0;
	    for(int i=0; i<n; i++) {
	        if(vis[i] || a[i].second == i) continue;
	        
	        int cyclesize = 0, j = i;
	        while(!vis[j]) {
	            vis[j] = true;
	            
	            j = a[j].second;
	            cyclesize++;
	        }
	        
	        if(cyclesize > 0) ans += cyclesize-1;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends