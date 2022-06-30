class Solution {
public:
    int search(vector<int>& nums, int t) {
        int l=0,r=nums.size()-1,mid=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(t == nums[mid]) return mid;
            else if(t > nums[mid]) l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
}; 