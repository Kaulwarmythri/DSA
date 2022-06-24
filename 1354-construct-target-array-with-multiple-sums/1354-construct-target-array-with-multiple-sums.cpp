class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = accumulate(target.begin(), target.end(), 0l);
        
        priority_queue<int> pq(target.begin(), target.end());
        
        while(pq.top() != 1) {
            auto largest = pq.top(); pq.pop();
            sum -= largest;
            
            if(largest <= sum || sum < 1) return false;
            
            largest %= sum;
            sum += largest;
            pq.push(largest ? largest : sum);    //take case [4, 1, 1]
        }
        
        return true;
        
    }
};