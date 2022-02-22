class Solution {
public:
    int titleToNumber(string colT) {
        int ans = 0;
        for(int i=0; i<colT.size(); i++)
            ans = ans*26 + (colT[i] - 'A' + 1);
        return ans;
    }
};