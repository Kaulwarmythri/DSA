bool compare(vector<int> v1, vector<int> v2){
    return v1[0] < v2[0] || (v1[0]==v2[0] && v1[1] >= v2[1]);
}
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        
        int ans = 0, prev = INT_MIN;
        for(auto interval : intervals){
            if(interval[1] > prev){
                ++ans;
                prev = interval[1];
            }
        }
        return ans;
    }
};