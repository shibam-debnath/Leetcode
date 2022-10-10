class Solution {
public:
    int candy(vector<int>& rt) {
        int n = rt.size(); 
        int ans=0;

        
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        
        //checking from left side
        for(int i=1;i<n;i++){
            // if greater than neighbour
            if(rt[i]>rt[i-1]){
                left[i] = left[i-1]+1;
            }
        }
        
        //checking from right side
        for(int i=n-2;i>=0;i--){
            // if greater than neighbour
            if(rt[i]>rt[i+1]){
                right[i] = right[i+1]+1;
            }
        }
        
        
        //finally take the max element of both
        for(int i=0;i<n;i++){
            ans+=max(left[i],right[i]);
        }
        
        return ans;
    }
};