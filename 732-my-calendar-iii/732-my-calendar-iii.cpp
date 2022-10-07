class MyCalendarThree {
    map<int, int> m;
    int maxcount = 0;
public:
    MyCalendarThree() {}
    
    int book(int s, int e) {
        m[s]++;
        m[e]--;
        int count = 0;
        
        for(auto &x: m) {
            count += x.second;
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */