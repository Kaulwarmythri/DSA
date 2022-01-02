class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        map<int, int> freq;
        
        for(auto &t : time){
            t %= 60;
            ans += t==0 ? freq[t] : freq[60-t];
            freq[t]++;
        }
        return ans;          
    }
};

/*
int ans = 0;
        for(auto &t : time){
            t %= 60;
        }
        
        for(auto &t : time){
            if(!t) ans++;
            else ans += count(time.begin(), time.end(), 60-t);
        }
        return ans;
*/