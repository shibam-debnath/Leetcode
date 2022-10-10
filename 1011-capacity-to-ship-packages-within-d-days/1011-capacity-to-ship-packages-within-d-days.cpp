class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n=weights.size();
        
        // decide the search space
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(suitable(mid,days,weights)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
    
    bool suitable(int capacity, int days,vector<int>& weights){
        int n=weights.size();
        int day_count =1;
        int wt=0;
        
        for(int i=0;i<n;i++){
            wt+=weights[i];
            if(wt>capacity){
                day_count++;
                wt = weights[i];
            }
        }
        return day_count<=days;
    }
};