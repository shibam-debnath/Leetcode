class Solution
{
    public:

        int mincostTickets(vector<int> &days, vector<int> &cost)
        {
            unordered_set<int> st(days.begin(),days.end()); // insert all the days to set 
            // 1d dp vector
            vector<int> dp(366);
            for (int i = 1; i < 366; i++)
            {
                //start from the first day
                // if we found that the day is present in days then do this 
                if (st.find(i)!=st.end())
                {
                   	// cost of ith day, decision of ith day will be
                    dp[i] = min({
                        // day pass
                        cost[0] + dp[i-1],  
                        // week pass
                        cost[1] + dp[max(0,i-7)],  //   since i-7 can be out of range we use this trick max(0,i-7)
                        // month pass
                        cost[2] + dp[max(0,i-30)]
                    });
                }
                else{
                    // not found in the days list then take the prev val
                    dp[i] = dp[i-1];
                }
            }
            
            return dp[365];
        }
};