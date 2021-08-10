class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;
        if(nums.size()==0){return v;}
        int beg,end;
        for(int i=0;i<nums.size();i=end+1){
            beg=end=i;
            while(end+1 < nums.size() && nums[end+1]==nums[end]+1) end++;
            if(end > beg) v.push_back(to_string(nums[beg]) + "->" + to_string(nums[end]));
            else v.push_back(to_string(nums[beg]));
        }
        return v;
        
    }
};