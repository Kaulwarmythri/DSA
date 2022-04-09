class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> m;
        priority_queue<pair<int, int>> pq; 
        
        for(auto i : nums) m[i]++;
        
        for(auto it=m.begin(); it != m.end(); it++) {
            pq.push({it->second, it->first});
        }
        
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
        
    }
};