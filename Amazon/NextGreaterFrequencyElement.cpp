// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void NGF(int arr[], int res[], int n)
{
    // arr[i] and freq
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    // insert arr[i] and freq
    stack<pair<int, int>> st;

    // insert last element with -1;
    st.emplace(arr[n - 1], -1); // -1 since no element in the righjt has greater freq
    res[n - 1] = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        int curr_freq = mp[arr[i]];
        // if curr freq stack k top freq se bhi bara h tab pop kr krke baaki elementys ko mcheck kro of stack jabtak stack exist krta ho
        if (!st.empty() && curr_freq >= st.top().second)
        {
            // same ya smaller st.top() hua to pop since we only want greater element
            st.pop();
        }

        // ans res pe push kro
        if (st.empty())
        {
            res[i] = -1;
        }
        else
        {
            res[i] = st.top().first;
        }

        // curr freq ko stack mein push kro
        st.emplace(arr[i], curr_freq);
    }
}

int main()
{
    int arr[] = {1, 1, 1, 2, 2, 2, 2, 11, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int res[n];
    NGF(arr, res, n);
    cout << "[";
    for (int i = 0; i < n - 1; i++)
    {
        cout << res[i] << ", ";
    }
    cout << res[n - 1] << "]";

    return 0;
}
