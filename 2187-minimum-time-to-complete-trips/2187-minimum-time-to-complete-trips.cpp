class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();
        long long l=0;
        long long r = 1e14+7;
        long long res =INT_MAX;
        
        while(l<=r){
            
            long long mid = l+(r-l)/2;
            
            long long trips = calculate(time,mid);
            
            if(trips >= totalTrips ){
                res = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        
        return res==INT_MAX?-1:res;
    }
    
    long long calculate(vector<int> &time, long long t){
        
        int n=time.size();
        long long hrs = 0;
        
        for(int i=0;i<n;i++){
            hrs += t/time[i];
        }
                
        return hrs;
    }
};