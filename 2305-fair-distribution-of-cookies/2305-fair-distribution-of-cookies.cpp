class Solution {
public:
    int distributeCookies(vector<int>& C, int k) {
        sort(C.begin(), C.end());
        
        int l = C[0], r = accumulate(C.begin(), C.end(), 0), ans = -1;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            
            if(isPossible(C, mid, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
    
    int isPossible(vector<int> &C, int mid, int k) {
        int n = C.size();
        
        do {
            int parts = 0, sum = 0; 
            for(int i=0; i<n; i++) {
                if(C[i] > mid) return false;
                sum += C[i];
                
                if(sum > mid) {
                    sum = C[i];
                    parts++;
                }
            }
            parts++;
            if(parts <= k)
                return true;
            
        } while(next_permutation(C.begin(), C.end()));
        
        return false;
    }
};