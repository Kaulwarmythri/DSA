class Solution {
public:
    int hIndex(vector<int>& citns) {
        int n = citns.size();
        vector<int> counts(n+1, 0);
        
        for(auto &c: citns) {
            if(c >= n) counts[n]++;
            else counts[c]++;
        }
        
        int cnt = 0;
        for(int i=n; i>=0; i--) {
            cnt += counts[i];
            if(cnt >= i) return i;
        }
        return 0;
        
    }
};