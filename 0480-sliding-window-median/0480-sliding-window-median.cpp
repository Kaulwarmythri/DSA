#define ll long long
class Solution {
    multiset<ll, greater<ll>> left;
    multiset<ll> right;
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> ans;
        
        for(int i=0; i<k; i++) {
            left.insert(nums[i]);
        }
        balanceSets();
        if(k & 1) 
            ans.push_back((double)*left.begin());
        else 
            ans.push_back(((double)*left.begin() + (double)*right.begin())/ 2.0);
        
        for(int i=k; i<n; i++) {
            if(nums[i] <= *left.begin()) {
                left.insert(nums[i]);
            } else {
                right.insert(nums[i]);
            }
            if(left.count(nums[i-k])) 
                left.erase(left.find(nums[i-k]));
            else 
                right.erase(right.find(nums[i-k]));
            balanceSets();
            
            if(k & 1) 
                ans.push_back((double)*left.begin());
            else 
                ans.push_back(((double)*left.begin() + (double)*right.begin())/ 2.0);
        }
        return ans;
    }
    
    void balanceSets() {
        while(right.size() > left.size()) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
        
        while(left.size() - right.size() > 1) {
            right.insert(*left.begin());
            left.erase(left.begin());
        }
    }
};