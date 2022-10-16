class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        nums.push_back(0);
        int n = nums.size(), left, top = 0, i = 0, ans = 0;
        stack<int> s;
        
        for(int i=0; i<n; i++) {
            while(s.size() && nums[s.top()] >= nums[i]) {
                top = s.top(); s.pop();
                left = s.empty() ? -1 : s.top();
                if(k > left && k < i)
                     ans = max(ans, nums[top] * (i - left - 1));
            }
            s.push(i);
        }
        return ans;
    }
};