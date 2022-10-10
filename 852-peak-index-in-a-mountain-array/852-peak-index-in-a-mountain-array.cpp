class Solution
{
    public:
       	// can be solved with O(logn) also
       	// find the occurance of first down slope
    
    
        // O(logN) solution
        int peakIndexInMountainArray(vector<int> &nums)
        {
            int ans = -1;
            int low = 0, high = nums.size()-1;
            
            while(low <= high){
                int mid = low + (high-low)/2;
                // find first occurance of down slope
                if(nums[mid]>nums[mid+1]){
                    ans = mid;
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            
            return ans;
        }
};