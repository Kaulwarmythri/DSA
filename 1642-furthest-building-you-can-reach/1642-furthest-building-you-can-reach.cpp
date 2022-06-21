class Solution {
public:
    int furthestBuilding(vector<int>& H, int B, int L) {
        int n = H.size(), i = 0, diff;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        while(i < n-1 && pq.size() < L) {
            diff = H[i+1] - H[i];
            if(diff > 0) {
                pq.push(diff);
            }
            i++;
        }
        
        while(i < n-1) {
            diff = H[i+1] - H[i];
            if(diff > 0) {
                if(pq.size() && pq.top() < diff) {
                    B -= pq.top(); pq.pop();
                    pq.push(diff);
                }
                else {
                    B -= diff;
                }
            }
            if(B < 0) return i;
            i++;
        }
        
        return i;
    }
};