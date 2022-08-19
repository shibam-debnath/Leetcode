class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int l=0;
        int r = 1e9+7;
        int res =INT_MAX;
        
        while(l<=r){
            
            int mid = l+(r-l)/2;
            
            double hours = calculate(dist,mid);
            
            if(hours <= hour ){
                res = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        
        return res==INT_MAX?-1:res;
    }
    
    
    double calculate(vector<int> &dist, int speed){
        
        int n=dist.size();
        double hrs = 0;
        
        for(int i=0;i<n-1;i++){
            hrs += ceil((double)dist[i]/(double)speed);
        }
        
        hrs += ((double)dist[n-1]/(double)speed);
        
        return hrs;
    }
};