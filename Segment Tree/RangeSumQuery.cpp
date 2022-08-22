// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class NumArray
{
public:
    int n = 0;
    vector<int> seg;
    NumArray(vector<int> &nums)
    {

        n = nums.size();
        seg.resize(4 * n, 0);

        if (n == 0)
            return;

        // build segment tree
        buildTree(nums, 0, 0, n - 1);
    }

    void buildTree(vector<int> &nums, int pos, int left, int right)
    {

        if (left == right)
        {
            seg[pos] = nums[left];
            return;
        }

        int mid = (left + right) / 2;

        buildTree(nums, 2 * pos + 1, left, mid);
        buildTree(nums, 2 * pos + 2, mid + 1, right);

        seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
    }

    void update(int index, int val)
    {
        updateUtil(0, 0, n - 1, index, val);
    }

    void updateUtil(int node, int st, int end, int index, int val)
    {

        // base case
        if (st == end)
        {
            seg[node] = val;
            return;
        }

        // seach in left and right subtree
        int mid = st + (end - st) / 2;

        if (index <= mid)
            updateUtil((2 * node) + 1, st, mid, index, val);

        else
            updateUtil((2 * node) + 2, mid + 1, end, index, val);

        // keep updating with new val while going up
        seg[node] = seg[(2 * node) + 1] + seg[(2 * node) + 2];
    }

    int sumRange(int left, int right)
    {
        if (n == 0)
            return 0;
        return query(0, 0, n - 1, left, right);
    }

    int query(int node, int st, int end, int l, int r)
    {

        // no overlap
        if (st > r or end < l)
            return 0;

        // complete overlap
        if (st >= l and end <= r)
            return seg[node];

        // partial overlap -> use divide and conquer
        int mid = (end + st) / 2;

        return query((2 * node) + 1, st, mid, l, r) + query((2 * node) + 2, mid + 1, end, l, r);
    }
};

int main()
{
    // Main function goes here
    return 0;
}

