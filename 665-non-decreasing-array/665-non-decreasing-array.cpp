class Solution
{
    public:
        bool checkPossibility(vector<int> &nums)
        {
            int n = nums.size();

            if (n == 1 || n == 2) return true;

            int flag = 0;

            for (int i = 1; i < n; i++)
            {

                if ((nums[i] < nums[i - 1]))
                {
                    flag++;
                   	//update one val in it's suitable position
                    if (i < 2 || (nums[i - 2] <= nums[i])) {
                        nums[i-1] = nums[i];
                    }
                    else{
                        nums[i] = nums[i-1];
                    }
                }

                if (flag >= 2)
                {
                    return false;
                }
            }

            return true;
        }
};