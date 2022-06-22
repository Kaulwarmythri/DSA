class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, ans = 0;
        priority_queue<int> pq;
        
        while(i < n) pq.push(nums[i++]);
        
        while(k) {
            ans = pq.top(); pq.pop();
            k--;
        }
        return ans;
    }
};