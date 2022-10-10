class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for(int i=1;i<10;i++){
            helper(n,k,i,res);    
        }
        return res;
    }
    
    void helper(int n, int k,int val,vector<int>&res){
        
        if(n==1){
            res.push_back(val);
            return;
        }
        
        if((val%10)-k>=0){
            // take it
            int t_val = val*10+((val%10)-k);
            helper(n-1,k,t_val,res);
        }
        
        if(k>0 and (val%10)+k<10){
            int t_val = val*10+((val%10)+k);
            helper(n-1,k,t_val,res);
        }
        
    }
};