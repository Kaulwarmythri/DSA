class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7;
        stack<pair<int, int>> prev, nxt;
        vector<long> left(n), right(n);
        
        for(int i=0; i<n; i++) left[i] = i;
        for(int i=0; i<n; i++) right[i] = n-i;
        
        for(int i=0; i<n; i++) {
            while(!prev.empty() && prev.top().first > arr[i]) 
                prev.pop();
            left[i] = prev.empty() ? i + 1 : i - prev.top().second;
            prev.push({arr[i], i});
            
            while(!nxt.empty() && nxt.top().first > arr[i]) {
                auto x = nxt.top(); nxt.pop();
                right[x.second] = i - x.second;
            }
            nxt.push({arr[i], i});
        }
        
        long ans = 0;
        
        for(int i=0; i<n; i++) {
            ans = (ans % mod + arr[i] * left[i] * right[i] % mod) % mod;
        }
        return ans;
    }
};
