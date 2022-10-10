class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int t) {
        vector<int> row;
        solve(nums,t,row,0);
        return res;
    }
    
    void solve(vector<int>& nums, int t,vector<int> row, int start){
        if(t==0) res.emplace_back(row);
        
        for(int i=start;i<nums.size();i++){
            if(nums[i] <= t){
                row.emplace_back(nums[i]);
                solve(nums,t-nums[i],row,i);
                row.pop_back();
            }
        }
        
        return;
    }
};