class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0 , sum=0;
        int min_gap = INT_MAX;
        for (int i = 0; i < n; i++) {
            
            // two pointer

            int l=i+1;
            int r=n-1;
            while(l<r){
                
                sum = nums[l]+nums[r];
                if(sum+nums[i]>target){
                    int gap = (sum+nums[i])-target;
                    if( gap < min_gap){
                        min_gap = sum+nums[i]-target;
                        res = sum+nums[i];
                    }
                    r--;
                }
                else if(sum+nums[i]<target){
                    int gap = target - (sum+nums[i]);
                    if(gap < min_gap){
                        min_gap = target - (sum+nums[i]);
                        res = sum+nums[i];
                    }
                    l++;
                }
                else{
                    res = sum+nums[i];
                    int left = nums[l];
                    while(l<r and nums[l] == left) l++;
                    int right = nums[r];
                    while(l<r and nums[r] == right) r--;
                }
            }
        }
        // cout << min_gap ;
        return res;
    }
};