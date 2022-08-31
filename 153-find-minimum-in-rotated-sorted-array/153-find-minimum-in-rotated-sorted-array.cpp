class Solution
{
public:
    
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
            
        int left = 0, right = n - 1, mid = 0;
        while(left<=right){
            mid=(right+left)/2;
            
            if(nums[mid]<nums[right]){
                // left side doesn't contain the rotated part
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return nums[mid];
    }
};