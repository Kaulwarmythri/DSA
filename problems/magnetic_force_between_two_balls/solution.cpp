class Solution {
public:
    bool isPossible(vector<int>& pos, int gap, int m) {  
        int left = pos[0]; 
        int count = 1;
        
        for(auto p : pos) {
            if(left + gap <= p) {
                count++;
                left = p;
            } 
        }
        
        return count >= m;
    }
    
    int maxDistance(vector<int>& pos, int m) {
        int n = pos.size();
        sort(pos.begin(), pos.end()); 
        int l = 0;
        int r = pos[n-1]-pos[0];
        int ans;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(isPossible(pos, mid, m)) { 
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        
        return l-1;
    }
};