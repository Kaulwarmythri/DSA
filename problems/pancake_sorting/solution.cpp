class Solution {
private:
    void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    void flip(vector<int> &arr, int i){
        int start = 0;
        while(start < i){
            int temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
            start++;
            i--;
        }
    }

public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n=arr.size(), maxIdx;
        
        for(int i=n; i>1; i--){ 
            maxIdx = max_element(arr.begin(), arr.begin()+i) - arr.begin();
            if(maxIdx == i) continue;
            flip(arr, maxIdx);
            flip(arr, i-1);
            
            ans.push_back(maxIdx+1);
            ans.push_back(i);
        }
        return ans;
    }
};