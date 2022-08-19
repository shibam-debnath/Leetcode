class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0;
        int r = arr.size()-1;
        
        while(l<=r){
            
            int mid = l+(r-l)/2;
            
            int gap = arr[mid]-mid-1;
            
            if(gap>=k){
                r=mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return k+l;
    }
};