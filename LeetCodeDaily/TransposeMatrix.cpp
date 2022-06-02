//Shibam Debnath
//May 26,2022
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> transpose(vector<vector<int>> &matrix)
{
    int n = matrix.size(), N = matrix[0].size();
    vector<vector<int>> B(N, vector<int>(n, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < n; j++)
            B[i][j] = matrix[j][i];
    return B;
}

int main() {
    //Main function goes here
    return 0;
}