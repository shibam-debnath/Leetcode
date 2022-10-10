class Solution
{
    public:
        int maxProfit(vector<int> &p)
        {
            int n = p.size();
            if (n == 1) return 0;

            int min_no = p[0];
            int ans = 0;
            for (int i = 1; i < n; i++)
            {
                ans = max(ans, p[i] - min_no);
                min_no = min(min_no, p[i]);
            }
            return ans;
        }
};