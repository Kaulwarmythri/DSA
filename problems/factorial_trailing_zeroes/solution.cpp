class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        while(n > 0){
            count += n/5;
            n /= 5;
        }
        return count;
        
        //number of zeroes is number of 2x5 's...So since 5 > 2, number of 5's can be easily          //calculated.
    }
};