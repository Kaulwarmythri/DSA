class Solution {
public:
    int totalFruit(vector<int>& A) {
        unordered_map<int, int> m;
        
        int n = A.size(), i = 0, j = 0;
        for(; j<n; j++) {
            m[A[j]]++;
            if(m.size() > 2) {
                if(--m[A[i]] == 0) m.erase(A[i]);
                i++;
            }
        }
        return j - i;
    }
};


//Longest length of a subarray with atmost 2 different numbers