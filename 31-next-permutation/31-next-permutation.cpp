class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();

        // refer video - https://www.youtube.com/watch?v=LuLCLgMElus

        // STEP 01 ::: storing (i-1)th increasing no
        int last_inc_idx = -1, greater_idx = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                last_inc_idx = i;
                break;
            }
        }

        // EDGE CASE ::: When the array is in decreasing order we'll find last_inc_idx so just sort the whole array
        if(last_inc_idx == -1){
            sort(nums.begin(), nums.end());
            return;
        }


        // STEP 02 ::: now find a number just greater than that in the right and store that
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] > nums[last_inc_idx])
            {
                greater_idx = i;
                break;
            }
        }

        // STEP 03 ::: swap and sort the array from position last_inc_idx+1 Since upto last_inc_idx we got our required prefix
        swap(nums[last_inc_idx], nums[greater_idx]);
        reverse(nums.begin()+last_inc_idx+1,nums.end());
    }
};
