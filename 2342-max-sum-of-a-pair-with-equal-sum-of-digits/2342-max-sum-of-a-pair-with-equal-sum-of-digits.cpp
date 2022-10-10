class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        int res=0;
        for(auto &x : nums){
            int sum = getSum(x);
            mp[sum].push_back(x);
        }
        for(auto m : mp){
            if(m.second.size()>1){
                sort(m.second.begin(),m.second.end(),greater<int>());
                res=max(res,m.second[0]+m.second[1]);
            }
        }
        return res>0?res:-1;
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