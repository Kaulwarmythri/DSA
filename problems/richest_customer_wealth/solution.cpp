class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi=0;
        for(auto person : accounts){
            int sum=0;
            sum = accumulate(person.begin(), person.end(), sum);
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};