bool compare(vector<int> &v1, vector<int> &v2){ 
    return v1[1] < v2[1]; 
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(), inter.end(), compare);
        
        int ans = 0, prev = INT_MIN; 
        for (auto& i : inter) 
            if (i[0] < prev) ++ans; 
            else prev = i[1]; 
        return ans; 
    }
};


