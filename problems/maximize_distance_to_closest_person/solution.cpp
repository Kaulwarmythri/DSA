class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size(), l=-1, i=0, maxDist = 0;
        
        for(; i<n; i++){
            if(seats[i] == 1){
                if(l == -1) maxDist = i;
                else maxDist = max(maxDist, (i-l)/2);
                l = i;
            }
        }
        if(seats[n-1] == 0) maxDist = max(maxDist, n-1-l);
        
        return maxDist;
    }
};