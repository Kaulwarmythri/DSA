class CombinationIterator {
private:
    set<string> combinations;
    set<string>::iterator cur;
public:
    CombinationIterator(string characters, int combinationLength) {
        int total = (1<<characters.size()); //No. of subsets = 2^n
        
        for(int mask=0;mask<total;mask++){
            
            if(__builtin_popcount(mask) != combinationLength) continue;
            
            string combination="";
            for(int i=0;i<characters.size();i++){
                if(mask&(1<<i)) combination+=characters[i];
            }
            combinations.insert(move(combination));
        }
        cur = combinations.begin();
    }
    
    string next() { return *cur++; }  
    
    bool hasNext() { return cur != combinations.end(); }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */