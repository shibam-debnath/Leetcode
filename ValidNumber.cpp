// Shibam Debnath
// May 26,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// The error conditions are :

//     More than one exponent character('e' / 'E'),
//     or seeing an 'e' / 'E' when a number has not yet been seen.More than one sign,
//     or a sign appearing after a decimal or number have been seen.This gets reset when passing an 'e' / 'E'.More than one decimal,
//     or a decimal appearing after an 'e' / 'E' has been seen.Any other non - number character appearing.Reaching the end of S without an active number.

bool isNumber(string S)
{
    bool num = false, exp = false, sign = false, dec = false;
    for (auto c : S) // first check for all the possible inputs. inside that check all the conditions if it is possible to get valid no or not
        if (c >= '0' && c <= '9') // no worries 
            num = true;
        else if (c == 'e' || c == 'E') // here  & e/E can't come after e and if num="" we can't only have e 
            if (exp || !num) return false; // direct re t false 
            else{
                // true == next it se  ye sab rehne se possible nehi h possible nehi h 
                exp = true, // true since we can't take other e
                sign = false, // we can have + or -
                num = false, // we can have num
                dec = false;  // we can have . 
            }
        else if (c == '+' || c == '-')
            if (sign || num || dec) // is no se pehle sign , num or decimel/. raha to false
                return false;
            else
                sign = true; // next sign is not possible
        else if (c == '.')
            if (dec || exp) // pehle wala part
                return false;
            else
                dec = true; // two dec is not possible
        else
            return false;
    return num;
}

int main()
{
    // Main function goes here
    return 0;
}