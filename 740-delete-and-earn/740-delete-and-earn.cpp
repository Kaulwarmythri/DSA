class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        
        vector<int> v(n+1, 0);
        
        for(auto num : nums) v[num] += num;
        int earn1 = 0, earn2 = v[1], currEarn = 0;
        
        for(int i=2; i<=n; i++){
            currEarn = max(earn2, v[i] + earn1);
            earn1 = earn2;
            earn2 = currEarn;
        }
        return max(earn2, earn1);
    }
};