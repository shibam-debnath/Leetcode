class Solution {
public:
    
    int fact[10] = {1,1,2,6,24,120,720,5040,40320,362880};
    
    string getPermutation(int n, int k) {
        string nums;
        for(int i=1;i<=n;i++) nums+=to_string(i);
        string s;
        k--; 
        for(int i=n;i>0;i--){
            int fac = fact[i-1];
            int idx = k/fac;
            k = k%fac;
            s.push_back(nums[idx]);
            nums.erase(nums.begin()+idx);
        }
        return s;
    }
};