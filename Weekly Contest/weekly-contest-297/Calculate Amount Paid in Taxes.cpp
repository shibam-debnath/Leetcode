// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    double calculateTax(vector<vector<int>> &b, int income)
    {
        int n = b.size();

        double res = 0;
        double inc = (double)b[0][0];
        double tax = (double)b[0][1] / 100;
        income = (double)income;

        if (income >= inc)
        {
            income -= inc;
            res = tax * inc;
        }
        else
        {
            res = tax * income;
            return res;
        }

        for (int i = 1; i < n; i++)
        {
            inc = (double)b[i][0] - (double)b[i - 1][0];
            tax = (double)b[i][1] / 100;
            if (income >= inc)
            {
                income -= inc;
                res += (inc * tax);
            }
            else
            {
                res += (tax * income);
                return res;
            }
        }

        return res;
    }
};

int main()
{
    // Main function goes here
    return 0;
}