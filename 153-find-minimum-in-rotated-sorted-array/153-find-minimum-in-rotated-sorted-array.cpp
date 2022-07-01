class Solution
{
public:
    
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
            
        int left = 0, right = n - 1, mid = 0;
        // whenever we find nums[l] < nums[r] then always nums[l] is the min val !try it in copy
        while (left < right)
        {
            mid = left + (right - left) / 2;

            if (nums[left] < nums[right])
            {
                // we found the sorted search space
                return nums[left];
            }
            
            // if nums[mid] is smaller than nums[left] matlab rotated part left m hein
            if (nums[left] > nums[mid])
            {
                // go to left kiuki waha rotated part hoga
                right = mid;
            }
            else if (nums[right] <= nums[mid])
            {
                // go to right
                left = mid + 1;
            }
        }
        return nums[left];
    }
};