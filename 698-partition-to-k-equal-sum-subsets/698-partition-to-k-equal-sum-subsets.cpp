class Solution {
private:
    
    int sum,target, all_one, n;
    
    bool isPossible(vector<int>& nums, int k, int vis, int curr,vector<int>& memo) {
       
        if(curr == target) {
            k--;
            curr = 0;
        }
        
        // Base cases
        
        if(k < 0 || curr > target) return false;
        if(vis == all_one && k==0 && curr==0) return true;
        
        // memoization
        if(memo[vis] != -1) return memo[vis];
        
        bool ans = false;
        for(int i = 0; i<n; i++) {
//              not visited
            if((vis & (1 << i)) == 0){
//                                                make visited    current sum
                ans = ans || isPossible(nums, k, vis | (1 << i), curr+nums[i],memo);
            } 
        }
        
        return memo[vis] = ans;
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        n = nums.size();
        
        // this basicaly checks if visited or not , 1 :: visited , 0 :: not visited
        all_one = (1 << n) - 1; // initialized with all one

        sum = accumulate(nums.begin(), nums.end(), 0);
        int vis = 0;
        
        vector<int> memo(all_one ,-1);
        
        if(sum%k != 0) return false;
        else target = sum / k;
        
        return isPossible(nums, k, vis, 0,memo);
    }
};