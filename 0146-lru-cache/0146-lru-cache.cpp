class Node {
public:
    int key, val;
    Node *next, *prev;
    
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
    
    Node(int key, int val, Node *next, Node *prev) {
        this->key = key;
        this->val = val;
        this->next = next;
        this->prev = prev;
    } 
};

class LRUCache {
    int capacity;
    
    unordered_map<int, Node*> m;
    
    Node *head = new Node(-1, -1, NULL, NULL);
    Node *tail = new Node(-1, -1, NULL, NULL);
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void insert(Node *cur) {
        cur->next = head->next;
        head->next->prev = cur;
        head->next = cur;
        cur->prev = head;
        
        m[cur->key] = cur;
        
    }
    
    void remove(Node *cur) {
        m.erase(cur->key);
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        
        Node *cur = m[key];
        remove(cur);
        insert(cur);
        
        return cur->val;
    }
    
    void put(int key, int val) {
        if(m.find(key) != m.end()) {
            remove(m[key]);
            
        }
        
        if(m.size() == capacity) {
            remove(tail->prev);
        }
        Node *newNode = new Node(key, val);
        insert(newNode);
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */