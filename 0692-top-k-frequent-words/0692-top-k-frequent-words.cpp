class comp {
public:
    bool operator()(pair<string, int> &a, pair<string, int> &b) {
            return a.second < b.second || a.second == b.second && a.first > b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        
        for(auto &w: words) m[w]++;
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, comp> pq; 
        
        for(auto &x: m) {
            pq.push({x.first, x.second});
        }
        
        vector<string> ans;
        while(k--) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};