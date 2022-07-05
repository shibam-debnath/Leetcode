class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        if(num%3!=0) return ans;
        
        long long mid = num/3;
        return {mid-1,mid,mid+1};
    }
};