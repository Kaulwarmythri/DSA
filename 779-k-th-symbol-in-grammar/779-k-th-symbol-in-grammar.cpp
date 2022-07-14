class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1 && k == 1) return 0;
        
        int mid = pow(2, n-1)/2;
        
        if(k <= mid) return kthGrammar(n-1, k);
        else return !kthGrammar(n-1, k-mid);
    }
};


// int kthGrammar(int n, int k) {
//         if(n == 0) return 0;
//         if(!(k%2)) return kthGrammar(n-1, k/2) == 0 ? 1 : 0;
//         else return kthGrammar(n-1, (k+1)/2) == 0 ? 0 : 1;
//     }