class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        #define ll long long
        unordered_map<ll, ll> m;   //stores pf counts of gcd(num, k) num in array nums
        
        ll ans = 0;
        for(auto &n: nums) {
            int curr = __gcd(n, k);
            for(auto &[g, cnt]: m) {
                if(g * curr % k == 0) 
                    ans += cnt;
            }
            m[curr]++;
        }
        return ans;
    }
};


//For a no. 'a' to be divisible by 'k'...All prime factors of 'k' should be present in 'a'.

//How can we conclude that a * b divides 'k' if gcd(a, k) * gcd(b, k) divides k.

//gcd(num, k) => common prime factors of num, k. So if gcd(a, k) * gcd(b, k) divides k =? All prime factors of k are present in their multiplication. 