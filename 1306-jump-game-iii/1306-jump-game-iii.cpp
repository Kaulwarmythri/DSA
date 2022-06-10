class Solution {
public:
    bool canReach(vector<int>& arr, int curr) {
        int n = arr.size();
        queue<int> q; q.push(curr);
        
        while(!q.empty()) {
            curr = q.front(); q.pop();
            
            if(arr[curr] == 0) return true; //reached the element 0
            if(arr[curr] < 0) continue; //will be stuck in an infinite loop
            
            if(curr + arr[curr] < n) q.push(curr + arr[curr]);
            if(curr - arr[curr] >= 0) q.push(curr - arr[curr]);
            
            arr[curr] *= -1;
        }
        return false;
    }
    
};