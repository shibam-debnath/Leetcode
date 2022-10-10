class Solution
{
    public:
        int beautySum(string s)
        {
            int res = 0;
            for (int i = 0; i < s.size(); i++)
            {
                unordered_map<char, int> mp;

                for (int j = i; j < s.size(); j++)
                {
                    mp[s[j]]++;
                    int mx = INT_MIN, mn = INT_MAX;

                    for (auto it: mp)
                    {
                        mx = max(mx, it.second);
                        mn = min(mn, it.second);
                    }

                    res += (mx - mn);
                }
            }
            return res;
        }
};