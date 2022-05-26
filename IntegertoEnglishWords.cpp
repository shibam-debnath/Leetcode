// Shibam Debnath
// May 26,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s = "";

vector<string> ones = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
vector<string> tens = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string numberToWords(int num)
{
    if (num == 0)
    {
        return "Zero";
    }
    else
    {
        string ret = func(num);
        // to handle beg spaces
        return ret.substr(1, ret.length() - 1);
    }
}

string func(int num)
{
    // edge case
    if (num == 0)
    {
        return "";
    }
    // base case
    if (num <= 19)
    {
        return " " + ones[num - 1];
    }
    else if (num == 20 || num == 30 || num == 40 || num == 50 || num == 60 || num == 70 || num == 80 || num == 90)
    {
        return " " + tens[num / 10 - 2];
    }
    else if (num <= 99)
    {
        return " " + tens[num / 10 - 2] + func(num % 10); //-2 since in ten's place we are starting from twenty
    }
    // hundred
    else if (num <= 999)
    {
        return func(num / 100) + " Hundred" + func(num % 100); // 900 ka kam ho gaya ab 99 ko bhejo
    }
    // thousand
    else if (num <= pow(10, 6) - 1)
    {
        return func(num / 1000) + " Thousand" + func(num % 1000); // hazar ka kam ho gaya ab 99 ko bhejo
    }
    // Million
    else if (num <= pow(10, 9) - 1)
    {
        return func(num / 1000000) + " Million" + func(num % 1000000); // hazar ka kam ho gaya ab 99 ko bhejo
    }
    else
    {

        return func(num / 1000000000) + " Billion" + func(num % 1000000000); // hazar ka kam ho gaya ab 99 ko bhejo
    }

    return "";
}
int main()
{
    // Main func goes here
    int n = 1352472;
    cout << func(n) << endl;
    return 0;
}