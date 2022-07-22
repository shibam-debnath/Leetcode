class Solution
{
    public:
        int leastInterval(vector<char> &tasks, int n)
        {
            
            unordered_map<char, int> mp;
            int max_freq = -1;
            for (auto &x: tasks)
            {
                mp[x]++;
                if (mp[x] > max_freq)
                {
                    max_freq = mp[x];
                }
            }
            
            int highest_freq_char_count = 0;
            
            for (auto i: mp)
            {
                if (i.second == max_freq) highest_freq_char_count++;
            }
            //            gap             highest   same wale excluding that one 
            int ans = n*(max_freq - 1) + max_freq +  highest_freq_char_count-1;
            
            //update ans
            int size = tasks.size();
            ans = max(ans,size);
            
            return ans;
        }   
};          