bool compare(vector<int> &v1, vector<int> &v2){ return v1[0] < v2[0]; }

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), compare);
        
        int prev=0;
        ans.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= ans[prev][1]){
                if(intervals[i][1] < ans[prev][1]) continue;
                else ans[prev][1] = intervals[i][1];
            }else{
                ans.push_back(intervals[i]);
                prev++;
            }
        }
        return ans;
    }
};