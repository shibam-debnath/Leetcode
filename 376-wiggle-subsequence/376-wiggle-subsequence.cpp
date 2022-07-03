class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        // LIS variation
        int n = nums.size();
        
        //base cases 
        if(n==1) return 1;
        
        int ans=0;
        if(nums[0]!=nums[1]) ans=2;
        else ans= 1;
        
        int last_diff=nums[1]-nums[0];
        for (int i = 2; i < n; i++)
        {
            int diff = nums[i]-nums[i-1];
            cout << diff << " ";
            if(diff > 0 && last_diff <= 0 || diff < 0 && last_diff >= 0 ){
                ans++;
                last_diff=diff;
            }          
        }
        cout << "\n";
        return ans;
    }
};