class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        int target = nums[(l+r)/2];
        long long ans=0;
        for(auto &x : nums){
            ans+= abs(x-target);
        }
        return ans;
    }
};