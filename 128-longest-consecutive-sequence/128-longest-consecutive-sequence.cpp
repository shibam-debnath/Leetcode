class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if( n == 1 || n == 0 ) return n;
        int max_len=0,len=1;

        sort(nums.begin(),nums.end());
        
        for(int i=1;i<n;i++){
            
            if(nums[i]==nums[i-1]){
                continue;
            }
            else if(nums[i]==nums[i-1]+1){
                // int curr_len = i-start;
                len++;
            }
            else{
                
                max_len=max(max_len,len);
                len=1;
                
            }
        }
        return max(max_len,len);
    }
};