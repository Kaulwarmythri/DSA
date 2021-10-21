class RandomizedSet {
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(s.count(val) != 0) return false;
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(s.count(val)==0) return false;
        s.erase(val);
        return true;
    }
    
    int getRandom() {
        auto it = s.begin();
        int random = rand()%s.size();
        std::advance(it, random);
        
        return *it;
    }
private:
    unordered_set<int> s;
    
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */