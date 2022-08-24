class Solution {
public:
    int arrangeCoins(int n) {
        int c=0;
        long long sum=0,i=0;
        while(sum + i <= n){
            sum+=i;   
            i++;
        }
        return i-1;
    }
};