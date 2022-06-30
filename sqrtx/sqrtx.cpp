class Solution {
public:
    int mySqrt(int x) {
        long long left=0,mid=0,end=x,temp_ans=0;
        while(end>=left){
            mid = (left+end)/2;
            if(mid*mid < x){
                left = mid+1;
                // since we may not get accurate , in that case we can return this closest val
                temp_ans=mid;
            }
            else if(mid*mid > x){
                end = mid-1;
            }
            else{
                // we found
                return mid;
            }
        }
        
        return temp_ans; // if we didn't find accurate wala
    }
};