class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int ans = INT_MAX, mini = INT_MAX;
        
        for(auto num : nums){
            if(num&1) num *= 2;
            mini = min(mini, num);
            pq.push(num);
        }
        while(!(pq.top()&1)){
            int x = pq.top()/2; pq.pop();
            pq.push(x);
            mini = min(mini, x);
            ans = min(ans, pq.top()-mini);   
        }
        return ans;
    }
};