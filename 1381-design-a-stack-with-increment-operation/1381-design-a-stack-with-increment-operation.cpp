class CustomStack {
    vector<int> A;
    int top;
public:
    CustomStack(int maxSize) {
        A = vector<int>(maxSize, 0);
        top = -1;
    }
    
    void push(int x) {
        if(top < (int) (A.size() - 1)) {
            A[++top] = x;
        }
    }
    
    int pop() {
        if(top >= 0) {
            return A[top--];
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<min(k, (int)(top + 1)); i++)
            A[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */