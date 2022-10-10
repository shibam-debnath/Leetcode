class Solution
{
    public:
        void merge(vector<pair<int, int>> &nums, int start, int mid, int end, vector< int > &ans)
        {
            vector<pair<int, int>> sorted(end - start + 1);

            int i = start;
            int j = mid + 1;
            int k = 0;

            while (i <= mid and j <= end)
            {
                if (nums[i].first <= nums[j].first)
                {
                    sorted[k] = nums[j];
                    j++;
                    k++;
                }
                else
                {
                    ans[nums[i].second] += end-j+1;
                    sorted[k] = nums[i];
                    i++;
                    k++;
                }
            }

            while (i <= mid)
            {
                sorted[k] = nums[i];
                i++;
                k++;
            }

            while (j <= end)
            {
                sorted[k] = nums[j];
                j++;
                k++;
            }

            i = start;
            k = 0;
            while (i <= end)
            {
                nums[i] = sorted[k];
                i++;
                k++;
            }
        }

    void mergeSort(vector<pair<int, int>> &nums, int start, int end, vector< int > &ans)
    {

        if (start < end)
        {
            int mid = start + (end - start) / 2;

            mergeSort(nums, start, mid, ans);
            mergeSort(nums, mid + 1, end, ans);
            merge(nums, start, mid, end, ans);
        }
        else return;
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        vector<pair<int, int>> numIndex(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            numIndex[i] = {nums[i],i};
        }

        vector<int> res(nums.size(), 0);

        mergeSort(numIndex, 0, nums.size() - 1, res);

        return res;
    }
};