class Solution {
public:
    int trailingZeroes(int N) {
        int c=0,zeros=5;
        while(zeros<=N){
            c+=(N/zeros);
            zeros=zeros*5;
        }
        return c;
    }
};