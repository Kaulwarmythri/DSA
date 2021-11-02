class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==0 || num==1) return true;
        
        long long l=1, r=num/2, mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(mid*mid==num) return true;
            else if(mid*mid > num) r=mid-1;
            else l=mid+1;    
        }
        return false;
        
    }
};