class LRUCache {
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it == m.end())
            return -1;
        l.splice(l.begin(), l, it->second);
        
        return l.begin()->second;
        
    }
    
    void put(int key, int val) {
        auto it = m.find(key);
        if(it != m.end()) {
            it->second->second = val;
            get(key);
            return;
        }
        
        if(m.size() == capacity) {
            int key = l.back().first;
            l.pop_back();
            m.erase(key);
        }
        l.push_front({key, val});
        m[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */