class Solution {
public:
    int furthestBuilding(vector<int>& H, int bricks, int ladders) {
        int i = 0, n = size(H), jumpHeight;
	
	    priority_queue<int, vector<int> ,greater<int> > pq;
        
        while (i < n - 1 && size(pq) < ladders) {
            jumpHeight = H[i + 1] - H[i];
            if(jumpHeight > 0) 
                pq.push(jumpHeight);
            i++;            
	    }
	
	    while (i < n - 1) {
            jumpHeight = H[i + 1] - H[i];
            
            if(jumpHeight > 0) {
			
                if(!pq.empty() && pq.top() < jumpHeight) {                    
                    
                    bricks -= pq.top(); pq.pop(); 
                    pq.push(jumpHeight);                    
                }
                else bricks -= jumpHeight;    
		    }
            if(bricks < 0) return i;
            i++;
        }
	    return i;
        
    }
};

