// Floyd Warshall Algorithm

#include <bits/stdc++.h>
using namespace std;

#define V 4 // V is no of cities
#define INF INT_MAX

// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall(int graph[][V])
{

    int dist[V][V];
    int i, j, k;

    // Initialize the solution matrix ( v-> no of cities)
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // We will have a 3 loops, checks if we can improve the distance between i and j by using k path.
    for (k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < V; j++)
            {
                // If through k we can have a short path from i to j then update that else ignore
                //     note such that both aren't inf             i->k dis      k->j dis
                if ((dist[k][j] != INF && dist[i][k] != INF) && (dist[i][k] + dist[k][j]) < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // use this matrix obtained for your ans
    // printSolution(dist);
}

void printSolution(int dist[][V])
{
    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF"
                     << "	 ";
            else
                cout << dist[i][j] << "	 ";
        }
        cout << endl;
    }
}

// Driver code
int main()
{
    /* Let us create the following weighted graph  */

    // here 0 -> distance to reach from i to i is 0 (when i==j)
    // INF values are those values which are not given
    // if graph[i][j] = 5 -> distance from i to j is 5

    int graph[V][V] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};

    // Print the solution
    floydWarshall(graph);
    return 0;
}
