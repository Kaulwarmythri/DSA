class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        unordered_map<int,int> mp;
        
        for(auto &it: nums1) mp[it]++; 
        for(auto &it: nums2){
            if(mp[it]>0){
                v.push_back(it);
                mp[it]--;
            }
        }
        return v;
    }
};