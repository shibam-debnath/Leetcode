#include <bits/stdc++.h>
using namespace std;

struct node
{
    int even = 0;
    int odd = 0;
    map<int, int> freq;
};
template <class T>
struct SegTree
{
    const T ID = node();
    int n;
    vector<T> seg;
    node comb(node a, node b)
    {
        for (auto &[e, cnt] : b.freq)
            a.freq[e] += cnt;
        a.even = 0;
        a.odd = 0;
        for (auto &[e, cnt] : a.freq)
        {
            if (cnt % 2)
                a.odd++;
            else
                a.even++;
        }
        return a;
    }
    SegTree(int _n)
    {
        n = _n;
        seg.assign(2 * n, ID);
    }
    void pull(int p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }
    void update(int idx, T val)
    {
        seg[idx += n] = val;
        for (idx /= 2; idx; idx /= 2)
            pull(idx);
    }
    T query(int l, int r)
    {
        T lnode = ID, rnode = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2)
        {
            if (l & 1)
                lnode = comb(lnode, seg[l++]);
            if (r & 1)
                rnode = comb(seg[--r], rnode);
        }
        return comb(lnode, rnode);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<node> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        a[i].freq[x] = 1;
        a[i].odd = 1;
        a[i].even = 0;
    }
    SegTree<node> seg(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        seg.update(i, a[i]);
    }
    while (q--)
    {
        for (int i = 1; i <= n; ++i)
        {
            auto d = seg.query(i, i);
        }
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
        {
            a[l].freq.clear();
            a[l].even = 0;
            a[l].freq[r] = 1;
            a[l].odd = 1;
            seg.update(l, a[l]);
        }
        else
        {
            int ans = seg.query(l, r).odd;
            cout << ans << " ";
        }
    }
    cout << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}