class Solution
{
    public:
        int findPeakElement(vector<int> &nums)
        {
            int n = nums.size();
            if (n == 1) return 0;
            if (n == 2) return nums[0] > nums[1] ? 0 : 1;
           	// to handle edge cases we are starting from 1 to n-2
            int i = 1, j = n - 2;
            while (i <= j)
            {
                int mid = j + (i - j) / 2;
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
                else if (nums[mid + 1] > nums[mid]) i = mid + 1;	// go right agar right wala bada dikhe to
                else if (nums[mid - 1] >= nums[mid]) j = mid - 1;	// go left agar left wala bada dikhe
            }
           	// handle edge cases
            if (nums[0] > nums[1]) return 0;
            else if (nums[n - 1] > nums[n - 2]) return n - 1;
            return -1;
        }
};