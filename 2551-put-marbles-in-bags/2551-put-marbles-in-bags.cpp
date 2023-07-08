class Solution {
public:
    long long putMarbles(vector<int>& W, int k) {
        long long n = W.size() - 1, ans = 0;
        
        for(int i=0; i<n; i++) 
            W[i] += W[i+1];
        
        W.pop_back();
        sort(W.begin(), W.end());
        
        for(int i=0; i<k-1; i++) {             //to pick k-1 mins and k-1 maxs
            ans += W[n-1-i] - W[i];
        }
        return ans;
    }
};


//In bith min and max scores, W[0] & W[n-1] are added and they cancel each other out
//When we put a subarray of marbles in a bag, we're only concerned about the first and last elements of the subarray
//We need to make "k-1" cuts in the array to put into "k" bags
//When we make a cut we're adding adjacent elements at the cut to the score of that particular distribution of marbles (Eg: [1, 3 | 5, 1] -> Score = 1 + 3 + 5 + 1 => Can be written as -> (1) + (3 + 5) + (1));
//So we add up all adjacent elements, push them into an array and sort that array.
//If we need min and max scores, we get it by adding (k-1) min elements and (k-1) max elements of that array and subtracting this "min" from "max" is the answer