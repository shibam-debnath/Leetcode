class NumArray
{
    public:
    vector<int> v{0};
    NumArray(vector<int> &nums)
    {
        int sum=0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            v.push_back(sum);
        }
    }

    int sumRange(int left, int right)
    {
        return v[right+1] - v[left];
    }
};

/**
 *Your NumArray object will be instantiated and called as such:
 *NumArray* obj = new NumArray(nums);
 *int param_1 = obj->sumRange(left,right);
 */