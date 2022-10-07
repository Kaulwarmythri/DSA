class MyCalendar {
    vector<pair<int, int>> cal;
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        for(auto &c: cal) {
            if(max(c.first, start) < min(c.second, end)) return false;
        }
        cal.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */