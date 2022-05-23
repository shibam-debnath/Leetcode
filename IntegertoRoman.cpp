// Shibam Debnath
// May 23,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
string intToRoman(int num)
{

    string s = ""; //    0   1     2    3    4   5    6   7   8  9  10 11 12
    int integer[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i = 0; i < 13; i++)
    {
        // ineach ineteger check how many times eg 1000 is coming. if 5000 the it comes out to be 5
        while (num > integer[i])
        {
            num -= integer[i];
            s += roman[i];
        }
    }

    return s;
}
int main()
{
    int num = 59;
    cout << intToRoman(num);
    return 0;
}