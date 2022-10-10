class Solution
{
    public:
        bool divideArray(vector<int> &nums)
        {
            int n = nums.size();
            unordered_map<int, int> mp;
            for (auto &x: nums)
            {
                mp[x]++;
            }
            for (auto &x: mp)
            {
                if (x.second &1)
                {
                    return false;
                }
            }
            return true;
        }
};