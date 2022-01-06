class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity){
        vector<pair<int, int>> inout;
        
        for(auto trip : trips){
            inout.push_back(make_pair(trip[1], trip[0]));
            inout.push_back(make_pair(trip[2], -trip[0]));
        }
        
        sort(inout.begin(), inout.end());
        
        for(auto &c : inout){
            capacity -= c.second;
            if(capacity < 0) return false;
        }
        return true;
    }
};












/*
bool carPooling(vector<vector<int>>& trips, int capacity){
        sort(trips.begin(), trips.end(), compare);
        
        capacity -= trips[0][0];
        for(int i=1; i<trips.size(); i++){
            capacity -= trips[i][0];
            if(trips[i][1] >= trips[i-1][2]) capacity += trips[i-1][0];
            if(capacity < 0) return false;   
        }
        return true;
}*/
