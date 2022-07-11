class Solution
{
public:
    vector<int> par, sizes;

    void make(int i)
    {
        par[i] = i;
        sizes[i] = 1;
    }

    // find function
    int find(int i)
    {
        if (par[i] == i)
            return i;
        return par[i] = find(par[i]);
    }

    // merges
    void Union(int i, int j)
    {
        // find their parents first
        i = find(i);
        j = find(j);

        if (i != j)
        {
            if (sizes[i] < sizes[j])
                swap(i, j);
            // since i==largest, So it is the root
            par[j] = i;
            // increase sizes of root
            sizes[i] += sizes[j];
        }
        par[j] = i;
    }

    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        par.resize(n);
        sizes.resize(n);

        int c = 0; // counts no of merges

        for (int i = 0; i < n; i++)
        {
            make(i);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // condition for union
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    Union(i, j);
                }
            }
        }
        
        // calculate remaining stones
        for (int i = 0; i < n; i++)
        {
            if(par[i]==i)c++;
        }

        return n-c;
    }
};