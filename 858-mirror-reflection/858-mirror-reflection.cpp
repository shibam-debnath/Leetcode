class Solution {
public:
    int mirrorReflection(int p, int q) {
        int side =1, ref = 1;
        while(p*side != ref*q){
            ref++;
            side = (q*ref)/p;
        }
        
        if(side%2==0 && ref%2==1) return 0;
        else if(side%2==1 && ref%2==1) return 1;
        else if(side%2==1 && ref%2==0) return 2;

        return 0;
    }
};