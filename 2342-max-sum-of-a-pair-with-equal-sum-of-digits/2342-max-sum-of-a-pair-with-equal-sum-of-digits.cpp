class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        int res=0;
        for( int i=0;i<n;i++){
            int dig_sum = getSum(nums[i]);
            mp[dig_sum].push_back(nums[i]);
        }
        
        for(auto m=mp.begin();m!=mp.end();m++){
            int size = mp[m->first].size();
            if(size>1){
                sort(mp[m->first].begin(),mp[m->first].end(),greater<int>());
                res=max(res,mp[m->first][0]+mp[m->first][1]);
            }
        }
        return res!=0?res:-1;
    }
    
    int getSum(int n)
    {
        int sum = 0;
        while (n != 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        return sum;
    }
};