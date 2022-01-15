class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        
        while(q.size()){
            auto curr = q.front(); q.pop();
            if(curr < 0 || curr >= arr.size() || arr[curr] < 0) continue;
            if(arr[curr] == 0) return true;
            q.push(curr+arr[curr]);
            q.push(curr-arr[curr]);
            
            arr[curr] *= -1;
        }
        return false;
    }   
};

