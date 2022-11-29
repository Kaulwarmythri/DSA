class RandomizedSet {
    unordered_map<int, int> m;
    vector<int> v;
    int size = 0;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(m.find(val) != m.end()) return false;
        
        m[val] = size;
        v.push_back(val);
        size++;
        
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;
        
        int idx = m[val];
        v[idx] = v.back();
        v.pop_back(); size--;
        m[v[idx]] = idx;
        
        m.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return v[rand() % size];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */