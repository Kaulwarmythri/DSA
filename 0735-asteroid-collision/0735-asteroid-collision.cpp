class Solution {
public:
    vector<int> asteroidCollision(vector<int>& A) {
        vector<int> ans;
        
        
        for(auto &x: A) {
            bool destroyed = false;
            while(ans.size() && ans.back() > 0 && x < 0 && !destroyed) {
                if(ans.back() >= -x) destroyed = true;
                if(ans.back() <= -x) ans.pop_back();
            }
            if(!destroyed) ans.push_back(x);
        }
        return ans;
    }
};