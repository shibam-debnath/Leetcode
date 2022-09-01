class Solution
{
   	// Time Complexity :::  O(n* log2(maxElement))
   	// Space Complexity ::: O(n)
    public:
        
        int minEatingSpeed(vector<int> &piles, int h)
        {
            int n = piles.size(), temp_ans = -1;
            int l = 1;	// since kok can eat min of 1 banana per hr
            int r = *max_element(piles.begin(), piles.end());
            
            while(l<=r){
                int mid_speed = l+(r-l)/2;
                long long time = KokoTakes(mid_speed,piles);
                
                if(time<=h){
                    // it can be a ans but try with smaller speed since we want min val of k
                    temp_ans = mid_speed;
                    r = mid_speed-1;
                }
                else{
                    l=mid_speed+1;
                }
            }
            return temp_ans;
        }
    
        long long KokoTakes(int speed, vector<int> &piles)
        {
            long long time_taken = 0;
            for (auto banana: piles)
            {
                if (banana % speed != 0) time_taken++;
                time_taken += banana / speed;
            }
            return time_taken;
        }
};