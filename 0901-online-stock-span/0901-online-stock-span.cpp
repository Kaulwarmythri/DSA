class StockSpanner {
    stack<pair<int, int>> s;
public:
    StockSpanner() {}
    
    int next(int price) {
        int res = 1;
        while(!s.empty() && s.top().first <= price) {
            auto [top, freq] = s.top(); s.pop();
            res += freq;
        }
        s.push({price, res});
        
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */