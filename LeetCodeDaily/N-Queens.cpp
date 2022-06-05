// Shibam Debnath
// June 03,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<string>> dp;

bool Safe(vector<string> v,int row, int col, int n)
{

    // check that row on left side

    for (int i = 0; i < col; i++)
    {
        if (v[row][i] == 'Q')
        {
            return false;
        }
    }

    int r = row, c = col;
    // check upper diagonal
    while (r >= 0 && c >= 0)
    {
        if (v[r--][c--] == 'Q')
        {
            return false;
        }
    }

    int a = row, b = col;
    // check lower diagonal
    while (a < n && b >= 0)
    {
        if (v[a++][b--] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void solve(vector<string>v,int col, int n)
{
    if (col >= n)
    {
        dp.push_back(v);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (Safe(v,i, col, n))
        {
            // if pos is safe then recursively check for safe pos in next col

            v[i][col] = 'Q';

            // check for next col

            solve(v,col + 1, n);

            //else backtrack

            v[i][col] = '.';
        }
    }
    // else continue;
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> v(n);

    if(n==0 || n<0){
        return {{}};
    }
    
    for (auto &x : v)
    {
        v.push_back(".");
    }

    int col = 0;
    solve(v,col, n);

    return dp;
}

int main()
{
    // Main function goes here
    return 0;
}