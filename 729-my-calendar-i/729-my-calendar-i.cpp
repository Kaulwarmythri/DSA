class MyCalendar { 
    vector<pair<int, int>> cal;
public:
    
    bool book(int start, int end) {
        for(auto &p: cal) {
            if(max(p.first, start)  < min(p.second, end)) return false;
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