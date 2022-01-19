class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> ans;
        int n=arr.size();
        int median=arr[(n-1)/2], l=0, r=n-1;
        
        while(l<=r){
            if(l==r) ans.push_back(arr[l]), l++;
            else if(abs(arr[l]-median) > abs(arr[r]-median)) ans.push_back(arr[l]), l++;
            else if(abs(arr[r]-median) > abs(arr[r]-median)) ans.push_back(arr[r]), r--;
            else{
                if(arr[r] > arr[l]) ans.push_back(arr[r]), r--;
                else ans.push_back(arr[l]), l++;
            }
            
            if(ans.size()==k) return ans;
        }
        
        return ans;
    }
};
