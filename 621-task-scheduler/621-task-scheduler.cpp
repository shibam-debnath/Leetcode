class Solution
{
    public:
        int leastInterval(vector<char> &tasks, int gap)
        {
            
            unordered_map<char, int> mp;
            int max_freq = -1;
            for (auto &x: tasks)
            {
                mp[x]++;
                max_freq=max(max_freq,mp[x]);
            }
            
            int highest_freq = 0;

            for (auto i: mp) if (i.second == max_freq) highest_freq++;
            int ans = gap*(max_freq - 1) + max_freq +  highest_freq-1;
            
            // edge case when 
            int size = tasks.size();
            ans = max(ans,size);
            
            return ans;
        }   
};          