class Solution {
public:
    int maxChunksToSorted(vector<int>& A) {
        int sum = 0, sorted_sum = 0, n = A.size(), ans = 0;
        
        for(int i=0; i<n; i++) {
            sum += A[i];
            sorted_sum += i;
        
            if(sum == sorted_sum)
                ans++;
        }
        return ans;
    }
};