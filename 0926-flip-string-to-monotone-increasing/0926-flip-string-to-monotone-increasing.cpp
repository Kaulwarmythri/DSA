class Solution {
public:
    int minFlipsMonoIncr(string s, int flips = 0, int ones = 0) {
        for(auto &c: s) {
            if(c == '1') 
                ones++;
            else 
                flips++;
            flips = min(flips, ones);
        }
        return flips;
    }
};