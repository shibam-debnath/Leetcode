class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        
        for(int pos=0;pos<32;pos++){
            //check each pos and count set bits
            int c=0;
            int bit_pos = 1<<pos; // binarywhere ith pos is set
            for(int j = 0; j < n; j++) {
                if(((nums[j]&bit_pos) != 0)) {
                    c+=1;
                }
            }
            
            // now set the bit of ans if c%3 != 0
            if((c%3)!=0) ans |= bit_pos;
            
        }
        
        return ans;
    }
};