class Solution
{
    public:
        vector<int> partitionLabels(string s)
        {
            int n = s.size();
            
            if(n==1) return {1};
            vector<int> ans;

            int end = 0, temp_end = 0, start = 0;

            while (end < n)
            {
                if (end == n - 1) return ans;

                end = s.find_last_of(s[start]);
                for (int i = start + 1; i < end; i++)
                {
                    int temp_end = s.find_last_of(s[i]);
                    if (temp_end > end)
                    {
                        if (end == n - 1)
                        {
                            return ans;
                        }
                        end = temp_end;
                    }
                }
                
                ans.push_back(end-start+1);
                start = end + 1;
            }
            return ans;
        }
};