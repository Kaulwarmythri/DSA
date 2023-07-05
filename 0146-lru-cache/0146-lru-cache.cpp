class LRUCache {
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;
    
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        
        auto p = m[key];
        
        l.splice(l.begin(), l, p);
        return l.begin()->second;
    }
    
    void put(int key, int val) {
        if(m.find(key) != m.end()) {
            auto it = m[key];
            
            l.splice(l.begin(), l, it);
            l.begin()->second = val;
            
            return;
        }
        
        if(l.size() == capacity) {
            int key = l.back().first;
            m.erase(key);
            l.pop_back();
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