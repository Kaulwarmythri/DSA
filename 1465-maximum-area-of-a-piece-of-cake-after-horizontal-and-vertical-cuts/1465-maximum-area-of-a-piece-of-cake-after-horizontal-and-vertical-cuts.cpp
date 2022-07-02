class Solution {
    int mod = pow(10, 9) + 7;
public:
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        sort(hor.begin(), hor.end()); sort(ver.begin(), ver.end());
        
        auto hl = max(hor[0], h - hor.back()), vl = max(ver[0], w - ver.back());
        
        for(auto i = 1; i<hor.size(); i++) hl = max(hl, hor[i] - hor[i-1]);
        
        for(auto i = 1; i<ver.size(); i++) vl = max(vl, ver[i] - ver[i-1]);
        
        return (long) hl * vl% mod;
        
        
    }
};