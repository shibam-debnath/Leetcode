class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((m*k) > n) return -1;
           
        int temp_ans = -1;
        int l = 1;	// since kok can eat min of 1 banana per hr
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        
        while(l<=r){
            
            int mid = l+(r-l)/2;
            bool possible = check(mid,bloomDay,m,k);
            
            if(possible){
                // it can be a ans but try with smaller speed since we want min val of k
                // cout << mid << " ";
                temp_ans = mid;
                r = mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return temp_ans;
    }
    
    bool check(int day,vector<int>&bloomDay,int m,int k){
        int n=bloomDay.size();
        int c = 0,res=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day){
                c++;
            }
            else{
                c=0;
            }
            
            if(c==k){
                res++;
                c=0;
            }
        }
        return res>=m;
    }
};