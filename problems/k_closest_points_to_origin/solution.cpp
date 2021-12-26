class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> dis, ans;
        
        int i=0;
        for(auto &p : points){
            dis.push_back({p[0]*p[0]+p[1]*p[1], i});
            i++;
        }
        
        i=0;
        sort(dis.begin(), dis.end());
        
        for(int i=0; i<k; i++){
            ans.push_back({points[dis[i][1]][0], points[dis[i][1]][1]});
        }
        
        return ans;
    }
};