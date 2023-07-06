class LFUCache {
    int capacity;
    int min_freq;
    
    unordered_map<int, list<pair<int, int>>> freq_lists;
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> pos;
    
    void insert(int key, int val, int freq) {
        freq_lists[freq].push_front({key, val});
        pos[key] = {freq, freq_lists[freq].begin()};
    }
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(pos.find(key) == pos.end()) return -1;
        
        int f = pos[key].first;
        auto it = pos[key].second;
        pair<int, int> kv = *it;
        
        freq_lists[f].erase(it);
        if(freq_lists[f].empty() && min_freq == f) min_freq++;
        insert(key, kv.second, f + 1);
        
        return freq_lists[f+1].begin()->second;
        
    }
    
    void put(int key, int val) {
        if(pos.find(key) != pos.end()) {
            auto f = pos[key].first;
            pos[key].second->second = val;
            
            get(key);
            return;
        }
        
        if(pos.size() == capacity) {
            pos.erase(freq_lists[min_freq].back().first);
            freq_lists[min_freq].pop_back();
        }
        
        min_freq = 1;
        insert(key, val, 1);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */