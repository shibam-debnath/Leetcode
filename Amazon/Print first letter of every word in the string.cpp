// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    string firstAlphabet(string S)
    {
        string str = "";
        if (S[0] != ' ')
            str.push_back(S[0]);
        for (int i = 1; i < S.size(); i++)
        {
            if (S[i - 1] == ' ')
            {
                str.push_back(S[i]);
            }
        }

        return str;
    }
};

int main()
{
    // Main function goes here
    return 0;
}