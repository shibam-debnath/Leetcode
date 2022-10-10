// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:

    int firstBadVersion(int n) {
        long long l=1,r=n,mid=0;
        int temp_ans=0;
        while(l<=r){
            // cout << mid <<" ";
            mid = (l+r)/2;
            if(isBadVersion(mid)){
                temp_ans=mid;
                r=mid-1;
            }
            else{
                // first bad is in right
                l=mid+1;
            }
        }
        return temp_ans;
    }
};