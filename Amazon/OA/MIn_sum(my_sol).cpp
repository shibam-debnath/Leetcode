#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> llegerToArray(ll x)
{
    vector<ll> resultArray;
    while (true)
    {
        resultArray.insert(resultArray.begin(), x % 10);
        x /= 10;
        if (x == 0)
            return resultArray;
    }
}

ll sumOfDigitsTwoParts(ll n)
{
    vector<ll> v = llegerToArray(n);
    sort(v.begin(), v.end());

    vector<ll> odd;
    vector<ll> even;

    ll n1 = 0, n2 = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (i % 2 != 0)
        {
            // odd
            odd.push_back(v[i]);
        }
        else
        {
            even.push_back(v[i]);
        }
    }
    reverse(odd.begin(), odd.end());
    reverse(even.begin(), even.end());
    for (int i = 0; i < odd.size(); i++)
    {
        n1 += odd[i] * pow(10, i);
    }

    for (int i = 0; i < even.size(); i++)
    {
        n2 += even[i] * pow(10, i);
    }

    // cout << endl
    //  << n1 << "  " << n2;

    return n1 + n2;
}

// Driver code
int main()
{
    ll test;
    cin >> test;
    while (test--)
    {
        ll n;
        cin >> n;
        cout << sumOfDigitsTwoParts(n);
    }

    return 0;
}
