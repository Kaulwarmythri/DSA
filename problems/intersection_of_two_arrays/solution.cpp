class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        set<int> s;
        vector<int> v;
        for(int i=0;i<nums1.size();i++){
            s.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            if(s.find(nums2[i]) != s.end()){
                v.push_back(nums2[i]);
            }
        }
        v.erase(unique(v.begin(),v.end()),v.end());
        return v;
    }
};