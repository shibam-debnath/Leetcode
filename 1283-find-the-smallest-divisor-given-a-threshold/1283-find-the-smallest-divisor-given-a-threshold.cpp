class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int t)
    {
        int n = nums.size();
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            bool possible = check(mid, nums, t);
            if (possible)
            {
                // it can be a ans but try with smaller speed since we want min val of k
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return l;
    }

    bool check(int d, vector<int> nums, int t)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) sum += ceil((float)nums[i] /(float) d);
        return sum<=t;
    }
};