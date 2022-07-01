class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int T) {
        int ans = 0, i=0;
        sort(b.begin(), b.end(), [](vector<int> v1, vector<int> v2) {
            return v1[1] > v2[1];
        });

        for(auto &x : b) {
            int boxes = min(x[0], T);
            ans += boxes * x[1];
            T -= boxes;
            if(!T) break;
        }
        return ans;
    }
};