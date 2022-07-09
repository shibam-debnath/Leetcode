class Solution {
public:
    int hammingDistance(int x, int y) {
        int c=0;
        while(x or y){
            if((x&1) != (y&1)) c++;
            x >>= 1;
            y >>= 1;
        }
        
        return c;
    }
};