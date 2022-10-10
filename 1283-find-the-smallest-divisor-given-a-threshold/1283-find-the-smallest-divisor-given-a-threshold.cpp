class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int t)
    {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        while(r>=l){
            int mid=l+(r-l)/2;
            
            int sum=get_sum(mid,nums,t);
            if(t>=sum)
                r=mid-1;
            else
                l=mid+1;
        }
        return l;
    }

    int get_sum(int d, vector<int>& nums, int t)
    {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]/d;
            if(nums[i]%d>0)
                sum++;
        }
        return sum;
    }
};