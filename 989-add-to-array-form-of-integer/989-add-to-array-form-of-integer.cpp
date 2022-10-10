class Solution
{
    public:
        vector<int> addToArrayForm(vector<int> &nums, int k)
        {
            int n = nums.size();
            reverse(nums.begin(),nums.end());
            
            int carry = 0;
            int i = 0, no = 0;
            
            while (k > 0 || carry)
            {

                int rem = k % 10;

                if (i > n - 1)
                {
                    no = carry + rem;
                    nums.push_back(no % 10);
                    carry = no / 10;
                }
                else
                {
                    int no = carry + rem + nums[i];
                    nums[i] = no % 10;
                    carry = no / 10;
                }

                k /= 10;
                i++;
            }
            reverse(nums.begin(),nums.end());
            return nums;
        }
};