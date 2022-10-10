class Solution
{
    public:
        vector<int> maxSubsequence(vector<int> &nums, int k)
        {
            priority_queue<pair<int, int>> pq;
            
            for (int i = 0; i < nums.size(); i++){
                pq.push({nums[i],i});
            }  
            vector<pair<int, int>> res;
            while (k--)
            {
                res.push_back({ pq.top().second, pq.top().first });
                pq.pop();
            }

            sort(res.begin(), res.end());
            nums.clear();
            
            for(auto &x : res){
                nums.push_back(x.second);
            }

            return nums;
        }
};