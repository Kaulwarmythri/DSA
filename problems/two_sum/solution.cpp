#include <bits/stdc++.h>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> v;
        unordered_map<int, int> indices;
        int i, numReq;
        unordered_map<int, int>::iterator p;
        for(i=0;i<nums.size();i++){
            numReq = target - nums[i];
            p = indices.find(numReq);
            if(p != indices.end()){
                v.push_back(p->second);
                v.push_back(i);
            }else{
                indices.insert(pair<int, int>(nums[i], i));
            }
        }
        return v;
    }
};