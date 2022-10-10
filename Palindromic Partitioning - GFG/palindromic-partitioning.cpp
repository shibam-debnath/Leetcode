// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    
    // variation 
    
    vector<vector<int>> dp;

    int palindromicPartition(string s)
    {
        int N = s.size();

        dp.resize(N, vector<int>(N, -1));

        return MCM(s, 0, N - 1);
    }
    
    int MCM(string &s, int i, int j)
    {
        // base case
        if (i >= j)
        {
            return 0;
        }

        // ! new addition
        if (palindrome(s, i, j))
        {
            return 0; // since no need to partition
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int mini = INT_MAX;

        // recursive call where we move k from i ton j-1

        for (int k = i; k <= j - 1; k++)
        {
            // int cost = arr[i - 1] * arr[k] * arr[j];
            // here cost is 1 for 1 partition
            int temp_ans = MCM(s, i, k) + MCM(s, k + 1, j) + 1;

            mini = min(mini, temp_ans);
        }

        return dp[i][j] = mini;
    }

    bool palindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends