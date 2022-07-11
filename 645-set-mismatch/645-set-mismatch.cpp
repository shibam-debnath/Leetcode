class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        int first=0,second=0;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                //find missing num , repeated is nums[i]
                first = nums[i];
            }
            mp[nums[i]]++;
        }
        sort(nums.begin(),nums.end());
        for(int i=1;i<=nums.size();i++){
            if(mp.find(i)==mp.end()){
                second = i;
                break;
            }
        }
        return {first,second};
    }
};