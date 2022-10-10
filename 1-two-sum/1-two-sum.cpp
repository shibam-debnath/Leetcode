class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int t = target-nums[i];
            if(mp.find(t)!=mp.end()){
                return {mp[t],i};
            }
            mp[nums[i]]=i;
        }
        
        return {0,0};
    }
};