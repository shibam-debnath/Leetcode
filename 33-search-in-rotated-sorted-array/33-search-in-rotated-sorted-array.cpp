class Solution
{
    public:
        int bs(vector<int> &nums, int t, int l, int r)
        {

            while (l <= r)
            {
                int m = l + (r - l) / 2;

               	// Check if x is present at mid
                if (nums[m] == t)
                    return m;

               	// If x greater, ignore left half
                if (nums[m] < t)
                    l = m + 1;

               	// If x is smaller, ignore right half
                else
                    r = m - 1;
            }

            return -1;
        }
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int diff = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                break;
            }
            else
            {
                diff++;
            }
        }
        sort(nums.begin(), nums.end());
        int ans = bs(nums, target, 0, nums.size() - 1);
        
        if(ans == -1) return -1;
        return (ans + diff) % n;
    }
};