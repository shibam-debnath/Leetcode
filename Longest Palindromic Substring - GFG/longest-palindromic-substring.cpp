// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        int n = s.size();

        int left;
        int right;
        int start = 0;
        int max_len = 0;

        int max_length = 0;

        for (int i = 0; i < n; i++)
        {
            int l = i - 1, r = i + 1;

            while (r < n && s[i] == s[r])
            {
                r++;
            }

            while (l >= 0 && s[i] == s[l])
            {
                l--;
            }

            while (r < n && l >= 0 && s[l] == s[r])
            {
                l--;
                r++;
            }

            int length = r - l - 1;

            if (length > max_len)
            {
                max_len = length;
                start = l + 1;
            }
        }

        return s.substr(start, max_len);
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends