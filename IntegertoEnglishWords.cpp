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
    // edge case
    if (num == 0)
    {
        return "Zero";
    }
    // base case
    if (num <= 19)
    {
        s = ones[num - 1];
        return s;
    }
    else if (num <= 99)
    {
        s = tens[num / 10 - 2] + " " + numberToWords(num % 10); //-2 since in ten's place we are starting from twenty
    }
    // hundred
    else if (num <= 999)
    {
        s = numberToWords(num / 1000) + " Hundred" + " " + numberToWords(num % 100); // 900 ka kam ho gaya ab 99 ko bhejo
    }
    // thousand
    else if (num <= pow(10, 6) - 1)
    {
        s = numberToWords(num / 1000) + " Thousand" + " " + numberToWords(num % 1000); // hazar ka kam ho gaya ab 99 ko bhejo
    }
    // Million
    else if (num <= pow(10, 9) - 1)
    {
        s = numberToWords(num / 1000000) + " Million" + " " + numberToWords(num % 1000000); // hazar ka kam ho gaya ab 99 ko bhejo
    }
    else
    {

        s = numberToWords(num / 1000000000) + " Billion" + " " + numberToWords(num % 1000000000); // hazar ka kam ho gaya ab 99 ko bhejo
    }

    return s;
}
int main()
{
    // Main function goes here
    int n = 1352472;
    cout << numberToWords(n) << endl;
    return 0;
}