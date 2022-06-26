class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while(pq.size() > 1) {
            auto first = pq.top(); pq.pop();
            auto sec = pq.top(); pq.pop();
            
            first -= sec;
            if(first > 0) pq.push(first);
        }
        return pq.size() ? pq.top() : 0;
    }
};