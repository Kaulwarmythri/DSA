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


//This is the kind of problem where CONTRIBUTION of every element is to be found. 
//The contibution of an element in this problem is (element) * (No. of subarrays such that this element is the minimum of them).
//No. of such subarrays = left * right -> left is the max length such that 'element' is the smallest in the subarrays on left which include 'element', right is the max length such that 'element' is the smallest on the right.

//So we basically need to find the prev smaller and next smaller elements and find the difference in length and multiply it.


//Let 
//1   8   7   3    4   2
//    <---m---><-n->           -> Here m = 3, n = 2
    
//No. of subarrays in which 3 is minimum 
//    => (m + n - 1) * (m + n) / 2 - (m - 1) * m /2 - (n - 1) * n /2 (m + n -1) because 3 is counted twice.
//m-1 => the array (8, 7) and all it's subarrays must be subtracted
//similarly n - 1
