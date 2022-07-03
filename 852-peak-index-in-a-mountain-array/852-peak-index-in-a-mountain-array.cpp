class Solution
{
    public:
       	// can be solved with O(logn) also
       	// find the occurance of first down slope
        int peakIndexInMountainArray(vector<int> &nums)
        {
            int low = 0, high = nums.size() - 1;
            int ans = -1;

            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (nums[mid]>nums[mid+1])
                {
                    ans = mid;
                    high = mid - 1;	// Look for better answer to the left
                }
                else
                {
                    low = mid + 1;
                }
            }

            return ans;
        }
};