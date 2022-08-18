class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size(), rem = n, ans = 0;
        unordered_map<int, int> freq;
        
        for(auto &num: arr) {
            freq[num]++;
        }
        priority_queue<int> pq;
        
        for(auto &f: freq) {
            pq.push(f.second);
        }
        while(rem > n/2) {
            auto top = pq.top(); pq.pop();
            rem -= top;
            ans++;
        }
        return ans;
        
    }
};