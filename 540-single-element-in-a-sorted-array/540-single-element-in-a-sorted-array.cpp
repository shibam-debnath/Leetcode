class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int l = 0, r = n - 1;
        while(l<=r){
            int mid = l+(r-l)/2;   
            int len = mid-l+1;
            if(mid-1>=0 and nums[mid-1]==nums[mid]){
                if(len%2==0) l=mid+1;
                else r=mid-2;
            }
            else if(mid+1<n and nums[mid+1] == nums[mid]){
                if(len%2==0) r = mid-1;
                else l=mid+2;
            }
            else return nums[mid];
        }
        return -1;
    }
};