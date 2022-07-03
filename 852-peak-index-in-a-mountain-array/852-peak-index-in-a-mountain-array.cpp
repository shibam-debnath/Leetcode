class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int prev_diff=arr[1]-arr[0];
        for(int i=2;i<arr.size();i++){
            int curr_diff = arr[i]-arr[i-1];
            if(prev_diff>0 && curr_diff<0 || prev_diff<0 && curr_diff>0){
                return i-1;
            }
            prev_diff=curr_diff;
        }
        return 0;
    }
};