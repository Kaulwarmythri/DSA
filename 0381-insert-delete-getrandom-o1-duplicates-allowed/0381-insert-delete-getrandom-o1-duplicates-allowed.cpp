class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> m;
    vector<int> v;
    int size = 0;
    
public:
    RandomizedCollection() {}
    
    bool insert(int val) {
        m[val].insert(size);
        v.push_back(val);
        size++;
        
        return m[val].size() == 1;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;
        
        int idx = *(m[val].begin());
        m[val].erase(m[val].begin());
        v[idx] = v.back(); 
        v.pop_back(); size--;
        
        m[v[idx]].insert(idx);
        m[v[idx]].erase(size);
        
        if(m[val].size() == 0) m.erase(m.find(val));
        return true;
    }
    
    int getRandom() {
        return v[rand() % size];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */