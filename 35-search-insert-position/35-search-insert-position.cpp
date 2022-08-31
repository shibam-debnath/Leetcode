class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        if(target>nums[r]) return r+1;
        while(l<=r){
            int mid =l+(r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                r--;
            } 
            else l++;
        }
        return l;
    }
};