class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> ens(n);
        
        for(int i=0; i<n; i++) {
            ens[i] = {efficiency[i], speed[i]};
        }
        sort(ens.begin(), ens.end(), greater<pair<int, int>>());
        
        priority_queue<int, vector<int>, greater<int>> pq; 
        long sumofs = 0, res = 0;
        
        for(auto &[e, s]: ens) {
            pq.push(s);
            sumofs += s;
            if(pq.size() > k) {
                sumofs -= pq.top(); pq.pop();
            }
            res = max(res, sumofs * e);
        }
        
        return res % (int)(1e9 + 7);
    }
};