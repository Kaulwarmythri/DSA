class Solution {
public:
    int minEatingSpeed(vector<int>& P, int h) {
        int l = 1, r = *max_element(P.begin(), P.end()), n = P.size();
        
        if(n == h) return r;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(count(P, mid) > h) l = mid + 1;
            else r = mid;
        }
        return l;
    }
    
    int count(vector<int> &P, int mid) {
        int cnt = 0;
        
        for(auto &x: P) {
            cnt += x / mid;
            if(x % mid) cnt++;
        }
        return cnt;
    }
};