class SmallestInfiniteSet {
    int cur = 1;
    set<int> s;    //add back set
public:
    SmallestInfiniteSet() {}
    
    int popSmallest() {
        if(s.size()) {     //that means we haven't popped anything yet
            int ans = *s.begin();
            s.erase(s.begin());
            
            return ans;
        }
        return cur++;
    }
    
    void addBack(int x) {
        if(x < cur) s.insert(x);     //cur increases only if we have popped from the infinite set
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */