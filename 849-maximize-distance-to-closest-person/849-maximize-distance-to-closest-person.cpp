class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int gap=0,max_gap=0;
        int start=0;
        for(int i=0;i<seats.size();i++){
            if(seats[i]==1){
                gap=i-start;
                max_gap = max(max_gap,gap);
                start=i;
            }
        }
        // this should be ans with edge cases
        max_gap/=2;
        
        // edge from left
        for(int i=0;i<seats.size();i++){
            if(seats[i]==1){
                max_gap=max(max_gap,i);
                break;
            }
        }
        
        // edge from right
        for(int i=seats.size()-1;i>=0;i--){
            if(seats[i]==1){
                int len = seats.size()-1-i;
                max_gap= max(max_gap,len);
                break;
            }
        }
        
        return max_gap;
    }
};