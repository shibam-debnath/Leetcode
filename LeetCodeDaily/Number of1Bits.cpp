//Shibam Debnath
//May 23,2022
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int hammingWeight(uint32_t n)
{
    int c=0;
    // Time Complexity: Θ(logn) (Theta of logn)
    while (n>0)
    {
        // n&1 checks if the bit is set or not 
        if (n&1 ==1)
        {
            c++;
        }
        n = n >> 1;
    }

    return c;
}
int main() {
    //Main function goes here
    return 0;
}