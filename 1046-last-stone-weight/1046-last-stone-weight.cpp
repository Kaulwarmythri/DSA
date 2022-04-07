class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        
        priority_queue<int> pq;
        
        for(int i=0; i<n; i++) pq.push(stones[i]);
        
        while(pq.size() > 1) {
            int first = pq.top(); pq.pop();
            int sec = pq.top(); pq.pop();
            
            if(first != sec) pq.push(first - sec);
        }
        return pq.empty() ? 0 : pq.top();
    }
};