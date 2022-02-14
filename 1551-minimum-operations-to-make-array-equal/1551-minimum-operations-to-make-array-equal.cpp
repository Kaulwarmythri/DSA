class Solution {
public:
    int minOperations(int n) {
        vector<int> arr(n);
        for(int i=0; i<n; i++) arr[i] = 2*i + 1;
        int target = (arr[0] + arr[n-1])/2, min_op=0;
        for(int i=0; i<n/2; i++) min_op += target - arr[i];
        
        return min_op;
    }
};