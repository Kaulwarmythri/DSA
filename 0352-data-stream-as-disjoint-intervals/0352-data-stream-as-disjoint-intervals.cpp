class SummaryRanges {
    set<int> nums;
public:
    SummaryRanges() {}
    
    void addNum(int val) {
        nums.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> I;
        int start = *nums.begin(), end = *nums.begin();
        
        for(auto it = ++nums.begin(); it != nums.end(); it++) {
            int val = *it;
            if(val - end == 1) {
                end = val;
            } else {
                I.push_back({start, end});
                start = end = val;
            }
        }
        I.push_back({start, end});
        return I;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */