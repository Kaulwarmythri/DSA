class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), 
             [](vector<int> a, vector<int> b){ return a[1] < b[1];});
        
        int n = courses.size(), total = 0;
        
        priority_queue<int> pq;
        
        for(auto &c: courses) {
            if(total + c[0] <= c[1]) {
                pq.push(c[0]);
                total += c[0];
            } else if(pq.size() && c[0] < pq.top()) {
                total += c[0] - pq.top(); pq.pop();
                pq.push(c[0]);    
            }
        }
        return pq.size();
    }
};