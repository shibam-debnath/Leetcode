// Shibam Debnath
// May 26,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct ListNode
{
    int val;
    ListNode *next;
};

int getDecimalValue(ListNode *head)
{
    int res = 0;
    while (head)
    {
        res = res * 2 + head->val;
        head = head->next;
    }
    return res;
}
int main()
{
    // Main function goes here
    return 0;
}