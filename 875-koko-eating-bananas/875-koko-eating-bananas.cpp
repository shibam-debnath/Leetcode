class Solution
{
    public:
    int KokoTakes(int speed,vector<int> &piles){
        unsigned long long time_taken=0;
        for(auto banana : piles){
            if(banana%speed!=0) time_taken++;
            time_taken += banana/speed;
        }
        return time_taken;
    }
        int minEatingSpeed(vector<int> &piles, int h)
        {
            int n = piles.size(),temp_ans = -1;

            int l = 1;	// since kok can eat min of 1 banana per hr
            int r = *max_element(piles.begin(), piles.end());
            int mid = 0;
            
        	//find occurance of first element from l to h (hour) when our API gives that yes koko can complete 
            
            while (l <= r)
            {
               	// mid = Koko eats mid bananas per hr
                mid = l + (r - l) / 2;

                unsigned long long time = KokoTakes(mid,piles);

                // if time required by koko is less than h hour
                if (time <= h)
                {
                    temp_ans = mid;
                   	//search for better sol
                    r = mid - 1;
                }
                else
                {
                    l= mid + 1;
                }
            }
            return temp_ans;
        }
};