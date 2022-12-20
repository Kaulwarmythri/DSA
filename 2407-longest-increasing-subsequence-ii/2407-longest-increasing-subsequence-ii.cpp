class SegTree {
    vector<int> seg;

public:
    SegTree(int n) {
        seg.resize(4 * n, 0);
    }
    
    int query(int ql, int qr, int l, int r, int idx = 0) {
        if(l > qr || r < ql) return 0;
        
        if(l >= ql && r <= qr) return seg[idx];
        
        int mid = l + (r - l) / 2;
        
        return max(query(ql, qr, l, mid, 2 * idx + 1), query(ql, qr, mid + 1, r, 2 * idx + 2));
    }
    
    void update(int l, int r, int pos, int val, int idx = 0) {
        if(pos < l || pos > r || l > r) return;
        
        if(l == r) {
            seg[idx] = val;
            return;
        }
        
        int mid = l + (r - l) / 2;
        if(mid >= pos) update(l, mid, pos, val, 2 * idx + 1);
        else update(mid + 1, r, pos, val, 2 * idx + 2);
        
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    
    int max_value() {
        return seg[0];
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size(), maxi = *max_element(nums.begin(), nums.end());
        SegTree *s = new SegTree(100005);
        
        for(int i=0; i<n; i++) {
            int l = max(1, nums[i] - k), r = nums[i] - 1;
            int val = s->query(l, r, 0, maxi);
            
            s->update(0, maxi, nums[i], val + 1);
        }
        
        return s->max_value();
    }
};