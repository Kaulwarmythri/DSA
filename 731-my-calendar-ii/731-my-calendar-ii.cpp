class MyCalendarTwo {
    map<int, int> m;
public:
    MyCalendarTwo() {}
    
    bool book(int s, int e) {
        m[s]++;
        m[e]--;
        
        int booked = 0;
        for(auto &x: m) {
            booked += x.second;
            
            if(booked == 3) {
                m[s]--;
                m[e]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */