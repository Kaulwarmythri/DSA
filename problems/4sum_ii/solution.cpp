class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count=0;
        map<int, int> m;
        
        for(auto &p1 : nums1){
            for(auto &p2 : nums2) m[p1+p2]++;
        }
        
        for(auto &p3 : nums3){
            for(auto &p4 : nums4) if(m.count(0-p3-p4)) count += m[0-p3-p4];
        }
        return count;
        
    }
};