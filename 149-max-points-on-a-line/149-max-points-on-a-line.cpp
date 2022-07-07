class Solution
{
    public:
        int maxPoints(vector<vector < int>> &points)
        {
            int n = points.size();
            if(n<=2) return n;
            
            int max_point = 0;
            double slope = 0;

            for (int i = 0; i < n; i++)
            {
                unordered_map<double, int> mp;
                for (int j = i + 1; j < n; j++)
                {
                    int y2 = points[j][1];
                    int y1 = points[i][1];

                    int x2 = points[j][0];
                    int x1 = points[i][0];

                    if (x1 == x2)
                    {
                        slope = INT_MAX;
                    }
                    else
                    {
                        slope = (double)(y2 - y1) / (double)(x2 - x1);
                    }
                    mp[slope]++;
                }

                for (auto slope: mp)
                {

                    max_point = max(max_point, slope.second);
                }
            }

            return max_point + 1;
        }
};