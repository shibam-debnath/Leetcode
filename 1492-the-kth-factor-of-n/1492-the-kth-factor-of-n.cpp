class Solution {
public:
    int kthFactor(int n, int k) {
        int c=0;
        int factor=0;
        for(int i=1;i<=n/2;i++){
            if(n%i==0){
                c++;
                if(c==k) return i;
            }
        }
        
        // since that no itself is a factor
        if(c+1==k) return n;
        
        return -1;
    }
};