//Shibam Debnath
//May 27,2022
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
string addStrings(string num1, string num2)
{
    
    int n = num1.size()-1;
    int m= num2.size()-1;
    int num = 0;
    string ans;
    while (n>=0 && m>=0 )
    {
        num += (num1[n] - '0') + (num2[m] - '0');
        ans+=(num % 10)+'0';
        num /= 10; //remainder
        n--;
        m--;
    }

    while (n>=0)
    {
        num += (num1[n] - '0');
        n--;
        ans += (num % 10) + '0';
        num /= 10; // remainder
    }

    while (m>=0)
    {
        num += (num2[m] - '0');
        m--;
        ans += (num % 10) + '0';
        num /= 10; // remainder
    }
    
    
    //if still rem is left
    if(num>0){
        ans += num + '0';
    }

    return ans;
}
int main() {
    //Main function goes here
    return 0;
}