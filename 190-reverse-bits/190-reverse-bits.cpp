class Solution
{
    
    // n>> 1 -> shifts one position to right 01010 -> 00101
    // n<< 1 -> shifts one position to left  01010 -> 10100
    
    public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0; 
        for(int i=0;i<32;i++){
            
            ans<<=1;
            ans = ans | (n&1);
            n>>=1;
            
        }
        return ans;
    }
};