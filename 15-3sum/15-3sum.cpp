class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            set<vector<int>> ans;
            vector<int> a;
            sort(nums.begin(), nums.end());
            int n = nums.size();

            int sum2 = 0;
            for (int i = 0; i < n; i++) {
                if(nums[i]>0) break;
                // two pointer
                int l=i+1;
                int r=n-1;
                while(l<r){
                    
                    int sum = nums[l]+nums[r];
                    if(sum+nums[i]==0){
                        ans.insert({nums[i],nums[l],nums[r]});
                        l++;
                        r--;
                    }
                    else if(sum+nums[i]>0){
                        r--;
                    }
                    else if(sum+nums[i]<0){
                        l++;
                    }
                }
            }
            vector<vector<int>> res;
            for(auto vec : ans) res.push_back(vec);
            return res;
        }
};