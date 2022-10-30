class Solution {
    int n;
public:
    int minDays(vector<int>& B, int m, int k) {
        n = B.size();
        if((long) m * k > n) return -1;
        int l = *min_element(B.begin(),B.end()), r = *max_element(B.begin(),B.end()), ans = 0;
        
        while(l <= r) {
            int mid = l + (r - l)/2;
            if(check(B, m, k, mid)) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
    
    bool check(vector<int> &B, int m, int k, int mid) {
        int bouquets = 0, num = 0;
        for(int i=0; i<n; i++) {
            if(B[i] <= mid && num < k) num++;
            else if(B[i] > mid && num < k) {
                num = 0;
                continue;
            }
            if(num == k) {
                bouquets++;
                num = 0;
            }
        }
        return bouquets >= m;
    }
};