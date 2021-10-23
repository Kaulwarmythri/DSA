class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        map<int, int> m;
        res = nums;
        sort(res.begin(), res.end());
        for(int i=res.size()-1;i>=0;i--){
            m[res[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            nums[i] = m[nums[i]];
        }
        return nums;
    }
};