class Solution {
public:
    
    // or create a no with all bits 1 of size as num
    // then xor both two
    
    int findComplement(int num) {
        int ones =0,temp=num;
        while(num){
            ones  = 1 | (ones<<1); 
            num>>=1;
        }
        
        return ones^temp; 
    }
};