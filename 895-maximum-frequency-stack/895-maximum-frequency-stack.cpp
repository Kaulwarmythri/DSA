class FreqStack {
public:
    map<int, int> freq_m; //stores the frequencies of elements as they're pushed into the freqStack
    map<int, stack<int>> freq_stk_m;
        
    int max_freq;
    
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int val) {
        freq_m[val]++;
        
        max_freq = max(max_freq, freq_m[val]);
        
        freq_stk_m[freq_m[val]].push(val);
    }
    
    int pop() {
        int currTop = freq_stk_m[max_freq].top();
        
        freq_m[currTop]--;
        
        freq_stk_m[max_freq].pop();
        
        if(freq_stk_m[max_freq].empty()){
            
            freq_stk_m.erase(max_freq);
            
            max_freq--;
            
        }
        
        return currTop;
        
        
    }
};

















/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */