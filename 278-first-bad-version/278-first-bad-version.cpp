// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:

    int firstBadVersion(int n) {
        long long l=1,r=n,mid=0;
        while(l<=r){
            // cout << mid <<" ";
            mid = (l+r)/2;
            if(isBadVersion(mid)){
                r=mid-1;
            }
            else{
                // first bad is in right
                l=mid+1;
            }
        }
        return l;
    }
};