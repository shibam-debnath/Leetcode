class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int all_xor=0;
        for(auto x:nums){
            all_xor^=x;
        }
        
        int diff_set_bit;
        for(int i=0;i<31;i++){
            if(all_xor & 1 << i) {
                diff_set_bit = i;
                break;
            }
        }
        // all xor == xor of two unique since remainig duplicates will cancel each other 
        // since this bit is set in all_xor means that in this position our required numbers have different bits
        // if we divide the numbers into two sections based on current bit position either 1 or 0.\
        // we'll get the required two numbers from these two sections by taking all xor of them -> similar to single number 1 problem 
        int xorr1=0,xorr2=0;
        for(auto x : nums){
            if((x&(1<<diff_set_bit))){
                xorr1^=x;
            }
            else{
                xorr2^=x;
            }
        }
        
        return {xorr1,xorr2};
    }
};