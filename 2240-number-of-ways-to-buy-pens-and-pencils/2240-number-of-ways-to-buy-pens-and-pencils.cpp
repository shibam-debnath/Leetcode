class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int total_pen = total/cost1;
        
        if(total < cost1 && total < cost2) return 1;
        
        // we'll calculate that if we buy 0 to total_pen , how many
        // pencils also can be brought
        
        long long ways=0;
        for(int i=0;i<=total_pen;i++){
            long long mon_rem = total - (i*cost1);
            int total_pencil = mon_rem/cost2 ; 
            
            //add both pen and pencil count
            ways+=total_pencil+1; // +1 is for pen combinations
        }
        
        return ways;
    }
};