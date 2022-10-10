class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            vector<vector<int>> ans;
            vector<int>a;
            sort(nums.begin(), nums.end());
            int n = nums.size();

            int sum = 0;
            for (int i = 0; i < n; i++) {
                
                if(i>0 and nums[i]==nums[i-1]) continue;
                
                // two pointer
                int l=i+1;
                int r=n-1;
                while(l<r){
                    
                    sum = nums[l]+nums[r];
                    if(sum+nums[i]>0){
                        r--;
                    }
                    else if(sum+nums[i]<0){
                        l++;
                    }
                    else{
                        ans.push_back({nums[i],nums[l],nums[r]});
                        int left = nums[l];
                        while(l<r and nums[l] == left) l++;
                        int right = nums[r];
                        while(l<r and nums[r] == right) r--;
                    }
                }
                
            }
            return ans;
        }
};