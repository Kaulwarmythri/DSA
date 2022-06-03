class NumArray {
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sum.resize(n, 0);
        sum[0] = nums[0];
        
        for(int i=1; i<n; i++) {
            sum[i] = nums[i] + sum[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return sum[right];
        if(left) return sum[right] - sum[left-1];
        
        return -1;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */