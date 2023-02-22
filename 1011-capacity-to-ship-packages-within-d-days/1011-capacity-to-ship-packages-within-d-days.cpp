class Solution {
public:
    int shipWithinDays(vector<int>& W, int d) {
        int l = *max_element(W.begin(),W.end()), r = accumulate(W.begin(), W.end(), 0);
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(check(W, mid, d) <= d) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    
    int check(vector<int> &W, int mid, int D, int cur = 0, int needed = 1) {
        for(auto &w: W) {
            cur += w;
            if(cur > mid) needed++, cur = w;
        }
        return needed;
    }
};

