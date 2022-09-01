class Solution {
public:
    int findBestValue(vector<int>& arr, int t) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        // decide the search space
        int low = 0;
        int high = t;
        int min_diff= INT_MAX;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            int diff1 = get_sum(mid,arr,t);
            int diff2 = get_sum(mid+1,arr,t);

            if(diff1<=diff2){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
    
    int get_sum(int d,vector<int>& arr,int t){
        int sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += min(arr[i], d);
        }
        return abs(sum-t);
    }
};