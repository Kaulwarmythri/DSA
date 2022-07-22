class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> gt;
        int n = nums.size(), j = 0, cnt = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] < pivot) nums[j++] = nums[i];
            else if(nums[i] == pivot) cnt++;
            else gt.push_back(nums[i]);
        }
        while(cnt--) nums[j++] = pivot;
        for(int i=0; i<gt.size(); i++) nums[j++] = gt[i];
        return nums;
    }
};