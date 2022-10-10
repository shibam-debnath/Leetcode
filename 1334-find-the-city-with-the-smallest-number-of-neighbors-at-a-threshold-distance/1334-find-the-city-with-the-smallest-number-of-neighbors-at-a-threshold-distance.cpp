class Solution
{
    public:
#define INF INT_MAX
    int findTheCity(int n, vector<vector < int>> &edges, int t)
    {
       	// use floyd warshall algo
        vector<vector < long long>> dist(n, vector < long long > (n, INF));

       	// Initialize the solution matrix (v-> no of cities)
        for (vector<int> e: edges)
        {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (int k = 0; k < n; k++)
        {
           	// Pick all vertices as source one by one
            for (int i = 0; i < n; i++)
            {
               	// Pick all vertices as destination for the above picked source
                for (int j = 0; j < n; j++)
                {
                   	// If through k we can have a short path from i to j then update that else ignore
                   	//     note such that both aren't inf             i->k dis      k->j dis
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int mn = INT_MAX, ans = 0;

        for (int i = 0; i < n; i++)
        {
            int c = 0;
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] <= t)
                {
                	// reachable
                    c++;
                }
            }

            if (c <= mn)
            {
                mn = c;
                ans = i;
            }
        }
        return ans;
    }
};