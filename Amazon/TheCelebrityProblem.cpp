// C++ program to find celebrity
#include <bits/stdc++.h>
#include <list>
using namespace std;

// Best Optimized Approach
// Time Complexity - O(n)
// Space Complexity - O(1)

// Max # of persons in the party
#define N 4

// Person with 2 is celebrity
bool MATRIX[N][N] = {{0, 0, 1, 0},
                     {0, 0, 1, 0},
                     {0, 1, 0, 0},
                     {0, 0, 1, 0}};

bool knows(int a, int b)
{
    return MATRIX[a][b];
}

int findCelebrity(int n)
{

    // assuming 0th person is the celeb
    int celeb = 0;
    // initial concepts ----
    //  1. if knows(a,b) then a can't be celeb and b can be a celeb , so celeb = b;
    //  2. if knows (celeb,b) or (b,k) where k is not the eceleeb then we have to return -1 since it is impossible case
    //  else we return celeb as ans;
    for (int i = 0; i < N; i++)
    {
        if (knows(celeb, celeb))
        {
            return -1;
        }
        // if b knows a then a is celeb
        if (knows(celeb, i))
        {
            // cout << i << endl;
            celeb = i;
            // in this qus we found(not sure) 2 is thew celeb
        }
    }
    // Now verify
    for (int j = 0; j < N; j++)
    {
        // case 1 : celeb knows anyone or
        if (knows(celeb, j))
        {
            return -1;
        }
        // case 2 : if any one(except celeb) does't know celeb
        if (j != 2 && knows(j, celeb) == 0)
        {
            cout << j << endl;
        }
    }
    return celeb;
}

// Driver code
int main()
{
    int n = 4;
    int id = findCelebrity(n);
    id == -1 ? cout << "No celebrity" : cout << "Celebrity ID " << id;
    return 0;
}
