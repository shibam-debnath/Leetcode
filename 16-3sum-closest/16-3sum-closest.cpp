class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0 , sum=0;
        int min_gap = INT_MAX;
        for (int i = 0; i < n; i++) {

            // two pointer
            int l=i+1;
            int r=n-1;
            while(l<r){

                sum = nums[l]+nums[r]+nums[i];
                int gap = abs(sum-target);
                if( gap < min_gap){
                    min_gap = gap;
                    res = sum;
                }
                if(sum>target){
                    r--;
                }
                else if(sum<target){
                    l++;
                }
                else{
                    return sum;
                }
            }
        }
        return res;
    }
};