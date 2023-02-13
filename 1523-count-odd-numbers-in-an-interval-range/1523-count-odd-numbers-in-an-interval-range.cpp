class Solution {
public:
    int countOdds(int low, int high) {
        int ans = (high - low) / 2;
        if(high & 1 || low & 1) ans++;
        
        return ans;
    }
};

//Half the numbers in any given range will be odd => (high - low) / 2 
//If either of low or high is odd => one more odd number is added => (high - low) / 2 + 1
//Simply (high + 1 - low) / 2; 