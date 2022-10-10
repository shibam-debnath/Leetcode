class Solution {
public:
    bool even(int n){
        
        long long sum=0;
        
        while(n>0){
            sum += n%10;
            n/=10;
        }
        
        return sum%2==0;
    }
    int countEven(int num) {
        long long ans=0;
        for(int i=2;i<=num;i++){
            if(even(i)){
                ans++;
            }
        }
        return ans;
    }
};