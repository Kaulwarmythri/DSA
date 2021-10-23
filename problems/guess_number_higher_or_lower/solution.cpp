/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l=1,r=static_cast<long long>(n)+1;
        while(l < r){
            int mid=l+(r-l)/2;
            if(guess(mid)==0) return mid;
            else if(guess(mid)==1) l=mid+1;
            else r=mid;
        }
        return l;
        
    }
};