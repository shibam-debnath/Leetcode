class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int gap=0,max_gap=0;
        int start=INT_MIN;
        for(int i=0;i<seats.size();i++){
            if(seats[i]==1){
                //left edge case
                if(start==INT_MIN){
                    max_gap = i;
                } 
                else{
                    gap=(i-start)/2;
                    max_gap = max(max_gap,gap);
                }
                start=i;
            }
        }
        
        // right edge case
        int right_gap = seats.size()-1-start;
        max_gap = max(max_gap,right_gap);
        
        return max_gap;
    }
};