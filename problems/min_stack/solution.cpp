class MinStack {
public:
     int min;
    class node{
        public:
        int currmin = INT_MAX;
        int val;
        node *next;
        node(int val){
            this->val = val;
        }
    };
    node*head = NULL;
    MinStack() {
    }
    
    void push(int val) {
        if(head == NULL)
            min = INT_MAX;
        node *t = new node(val);
        t->next = head;
        head = t;
        if(t->val < min){
           // we keep a currmin variable for each node to keep track of min value till that node.
            t->currmin = t->val;
            min = t->val;
        }
        else
            t->currmin = min;
    }
    
    void pop() {
        int res = head->val;
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        if(head != NULL)
        min = head->currmin;
        delete(temp);
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->currmin;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */