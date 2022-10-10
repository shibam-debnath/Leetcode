class Solution {
public:
    int minSteps(int n) {
        int div =2, ans=0;
        
        // do untill nums is 1
        while(n>1){
            
            while(n%div==0){
                n= n/div;
                ans+=div;
            }
            // keep incrementing div untill we find our n==1
            div++;
        }
        return ans;
    }
};