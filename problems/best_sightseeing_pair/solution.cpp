class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore=0;
        for(int i=1;i<values.size();i++){
            maxScore = max(values[i]+values[i-1]-1, maxScore);
            values[i] = max(values[i], values[i-1]-1);
        }
        return maxScore;
    }
};