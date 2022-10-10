class Solution {
public:

    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            int pos = nums[i]%n;
            nums[pos] += n;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]>2*n) return i;
        }
        return 0;        
    }
};