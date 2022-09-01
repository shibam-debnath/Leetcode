class Solution {
public:
    int trailingZeroes(int N) {
        int c=0,div=5;
        while(div<=N){
            c+=(N/div);
            div=div*5;
        }
        return c;
    }
};