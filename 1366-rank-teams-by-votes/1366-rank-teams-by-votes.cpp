class Solution
{
    public:

        string rankTeams(vector<string> &votes)
        {

            int n = votes[0].size();
            vector<vector < int>> rank(26, vector<int> (n, 0));

            for (auto &s: votes)
            {
                for (int i = 0; i < s.size(); i++)
                {
                    rank[s[i] - 'A'][i]++;
                }
            }

            string ans = votes[0];

            sort(ans.begin(), ans.end(), [& ](const char &a, const char &b)
            {
                if (rank[a - 'A'] == rank[b - 'A'])
                    return a < b;
                return rank[a - 'A'] > rank[b - 'A'];
	        });
            
            return ans;
        }
};