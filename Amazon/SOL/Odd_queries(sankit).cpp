// Shibam Debnath
// June,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> v(n), prefix(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        prefix[0] = v[0] & 1 ? 1 : 0;
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1];
            prefix[i] += v[i] & 1 ? 1 : 0;
        }
        while (q--)
        {
            int x, y, z;
            cin >> x >> y >> z;
            if (x == 2)
            {
                y--;
                z--;
                if (y > 0)
                    cout << prefix[z] - prefix[y - 1] << '\n';
                else if (y == 0)
                    cout << prefix[z] << '\n';
            }
            else if (x == 1)
            {
                if (z & 1)
                    continue;
                else if (z % 2 == 0 and v[y] % 2 == 1)
                {
                    v[y] = z;
                    while (y < n)
                    {
                        prefix[y]--;
                        y++;
                    }
                }
            }
        }
    }
    return 0;
}