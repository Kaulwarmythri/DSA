class NumArray {
private:
    vector<int> seg;
    vector<int> nums;
    int n;
    
    void buildSegTree(int l, int r, int idx = 0) {
        if(l == r) {
            seg[idx] = nums[l];
            return;
        }
        
        int mid = l + (r - l)/2;
        buildSegTree(l, mid, 2*idx+1);
        buildSegTree(mid+1, r, 2*idx+2);
        
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
    
    void updateSegTree(int i, int val, int l, int r, int idx = 0) {
        if(l > r || i < l || i > r) return;
        
        if(l == r) {
            seg[idx] = val;
            return;
        }
        int mid = l + (r - l)/2;
        if(mid >= i) updateSegTree(i, val, l, mid, 2*idx+1);
        else updateSegTree(i, val, mid+1, r, 2*idx+2);
        
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
    
    int sumQuery(int ql, int qr, int l, int r, int idx = 0) {
        if(ql > r || qr < l) return 0;
        
        if(l >= ql && r <= qr) return seg[idx];
        
        int mid = l + (r-l)/2;
        return sumQuery(ql, qr, l, mid, 2*idx+1) + sumQuery(ql, qr, mid+1, r, 2*idx+2);
    }
    
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        seg.resize(4 * n);
        
        buildSegTree(0, n-1);
    }
    
    void update(int index, int val) {
        updateSegTree(index, val, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return sumQuery(left, right, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */