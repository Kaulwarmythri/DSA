class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n = cit.size();
        
        sort(cit.begin(), cit.end());
        
        for(int i=0; i<n; i++) {
            if(cit[i] >= n-i) return n-i;
        }
        return 0;
    }
};