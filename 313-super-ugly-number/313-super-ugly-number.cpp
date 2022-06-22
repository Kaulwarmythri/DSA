#define P pair<long long, int>
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> index(primes.size(), 0);
        vector<long long> uglys;
        
        uglys.push_back(1);
        
        priority_queue<P, vector<P>, greater<P>> pq;
        
        for(int i=0; i<primes.size(); i++) pq.push({primes[i], i});
        
        while(uglys.size() < n) {
            auto [val, idx] = pq.top(); pq.pop();
            
            if(uglys.back() != val) uglys.push_back(val);
            
            index[idx]++;
            
            pq.push({uglys[index[idx]] * primes[idx], idx});
        }
        return uglys.back();
    }
};
