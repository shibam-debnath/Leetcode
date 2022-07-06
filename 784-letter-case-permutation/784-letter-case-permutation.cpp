class Solution
{
    public:
        vector<string> ans;
    vector<string> letterCasePermutation(string nums)
    {
        string v;
        permutations(0, nums, v);
        return ans;
    }

    void permutations(int i, string &nums, string &v)
    {
       	// base case
        if (i >= nums.size())
        {
            ans.push_back(v);
            return;
        }

       	// digit
        if (isdigit(nums[i]))
        {
            v.push_back(nums[i]);
            permutations(i + 1, nums, v);
            v.pop_back();
        }
        else
        {

           	// insert both lowercase and uppercase
            v.push_back(nums[i]);
            permutations(i + 1, nums, v);
            v.pop_back();

           	// insert uska alternate

            nums[i] = nums[i] ^ (1 << 5);	// this alters 5th pos in binary form So, lowercase becomes uppercase and vice versa
            v.push_back(nums[i]);
            permutations(i + 1, nums, v);	// again call the function 
            v.pop_back();
            
        }
    }
};