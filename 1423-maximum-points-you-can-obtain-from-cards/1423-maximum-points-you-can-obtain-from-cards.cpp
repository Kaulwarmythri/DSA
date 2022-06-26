class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size(), sum = accumulate(cp.begin(), cp.end(), 0), subArrSum = accumulate(cp.begin(), cp.end() - k, 0), ans = sum - subArrSum;
        for(int l = 0, r = n-k; r < cp.size(); l++, r++)
            ans = max(ans, sum - (subArrSum += cp[r] - cp[l]));
        
        return ans;   
    }
};
