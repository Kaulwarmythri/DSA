class Solution {
public:
    int eliminateMaximum(vector<int>& D, vector<int>& S) {
        int count = 0;
        int n = D.size();
        vector<double> T(n);

        for(int i = 0; i < n; i++)
        {
            T[i] = (double)D[i] / S[i];
        }

        sort(T.begin(), T.end());

        int t = 0;
        for(auto x : T) {
            if(x > t) count++, t++;
            
            else break;
        }
        return count;
    }
};
