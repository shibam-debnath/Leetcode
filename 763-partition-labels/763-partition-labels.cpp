class Solution
{
    public:
        vector<int> partitionLabels(string s)
        {
            int n = s.size();
            
            if(n==1) return {1};
            // unordered_map<char, int> mp;
            vector<int> ans;

            int end = 0, temp_end = 0, start = 0;

            while (end < n)
            {
                if (end == n - 1)
                {
                    // ans.push_back(end);
                    return ans;
                }
                end = s.find_last_of(s[start]);
                for (int i = start + 1; i < end; i++)
                {
                    int temp_end = s.find_last_of(s[i]);
                    if (temp_end > end)
                    {
                        if (end == n - 1)
                        {
                            return ans;
                            // ans.push_back(end);
                        }
                        end = temp_end;
                    }
                }
                
                ans.push_back(end-start+1);
                start = end + 1;
            }
            // ans.pop_back();
            return ans;
        }
};