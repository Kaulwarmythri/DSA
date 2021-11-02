class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c<3) return true;
        int l=0, r=sqrt(c);
        long long sos; //sos==>sumOfSquares
        while(l<=r){
            sos = (long long) l*l+r*r;
            if(sos==c) return true;
            else if(sos>c) r--;
            else l++;     
        }
        return false;
    }
};