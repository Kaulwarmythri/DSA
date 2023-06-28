class Solution {
public:
    long long totalCost(vector<int>& C, int k, int candidates) {
        int n = C.size(), i = 0, j = C.size() - 1;
        long long ans = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        
        while(k--) {
            while(i <= j && pq1.size() < candidates) pq1.push(C[i++]);
        
            while(i <= j && pq2.size() < candidates) pq2.push(C[j--]);

            int a = pq1.size() ? pq1.top() : INT_MAX;
            int b = pq2.size() ? pq2.top() : INT_MAX;

            if(a <= b) {
                ans += a;
                pq1.pop();
            } else {
                ans += b;
                pq2.pop();
            }
        }
        return ans;
    }
};
