// Shibam Debnath
// July,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1e5 + 10

vector<int> par(N), sizes(N);

// since we want min and max sizes mof group we'll use multiset here
multiset<int> m_set;

void make(int i)
{
    par[i] = i;
    sizes[i] = 1;
    m_set.insert(1);
}

void update_m_set(int a, int b)
{
    // first erase these two grps using their iterator and finally add the sum to multi set
    m_set.erase(m_set.find(sizes[a]));
    m_set.erase(m_set.find(sizes[b]));

    m_set.insert(sizes[a] + sizes[b]);
}

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
        // since i==largest , So it is the root
        par[j] = i;
        // update the sizes in multiset also
        update_m_set(i, j);
        // increase sizes of root
        sizes[i] += sizes[j];
    }
    par[j] = i;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    // everyonr is in their own group
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        Union(a, b);

        if (m_set.size() == 1)
            cout << 0 << endl;
        else
        {
            int mx = *(--m_set.end());
            int mn = *(m_set.begin());
            cout << mx - mn << endl;
        }
    }

    return 0;
}