class Solution {
public:
    long long minimumTime(vector<int>& T, int trips) {
        long long ltime = *min_element(T.begin(), T.end());
        long long rtime = 1e14;
        
        while(ltime < rtime) {
            long long mid = ltime + (rtime - ltime) / 2;
            if(check(T, mid) >= trips) rtime = mid;
            else ltime = mid + 1;
        }
        return ltime;
    }
    
    long long check(vector<int> &T, long long mid) {
        long long trips = 0;
        
        for(auto &x: T) {
            trips += mid / x;
        }
        return trips;
        
    }
};