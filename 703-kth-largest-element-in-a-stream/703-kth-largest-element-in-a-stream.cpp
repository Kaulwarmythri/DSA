class KthLargest {
    int k;
    multiset<int, greater<int>> s; 
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto num : nums) s.insert(num);
        
    }
    
    int add(int val) {
        s.insert(val);
        auto it = s.begin();
        for(int i=0; i<k-1; i++) it++;
        return *it;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */