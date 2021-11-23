class UnionFind {   //Create a separate class for the methods so that any DSU problem can be solved using the same class
public:
    vector<int> parent, rank;
    
    UnionFind(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); //Initializes parent such that parent[i] = i;
        rank.resize(n, 1);
    }
    
    int find(int i){  //To find the representative of an element
        if(parent[i] != i) parent[i] = find(parent[i]);
        
        return parent[i];
    }
    
    bool Union(int i, int j){    //Making j's the representaive of i's representative
        int i_rep = find(i), j_rep = find(j);
        if(i_rep == j_rep) return false;
        if(rank[i_rep] > rank[j_rep]) swap(i_rep, j_rep);
        parent[i_rep] = j_rep;
        rank[j_rep] += rank[i_rep];
        return true;
        
    }
};
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int m = (*max_element(nums.begin(), nums.end()) + 1);   //largest element
        
        vector<bool> present(m+1, false);
        for(auto num : nums) present[num] = true;  //If the element is present in 'nums', mark it as true;
        
        UnionFind *uf = new UnionFind(m+1);
        vector<bool> seive(m+1, true);
        seive[0] = seive[1] = false;  //We want only those numbers which are non-co-prime i.e; those numbers who have a factor greater than 1;
        
        
        for(int k=2;k<=m/2;k++){  //for every element smaller than the largest
            if(seive[k]){
                int prev_num = present[k] ? k : 0;  //If it is present in the array of nodes
                
                for(int p=2*k;p<=m;p+=k){
                    seive[p] = false;
                    if(present[p]){
                        if(prev_num) uf->Union(prev_num, p);   //If an element smaller is present, join both the sets
                        else prev_num = p;  //Otherwise assign this to 'prev_num'
                    } 
                }
            }
        }
        
        int ans = *max_element(uf->rank.begin(), uf->rank.end());  //Whichever has max rank
        delete uf;
        return ans;
        
    }
    
};

