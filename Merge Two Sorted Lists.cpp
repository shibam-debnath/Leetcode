// Shibam Debnath
// May 28,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct ListNode
{
    int val;
    ListNode *next;
};
ListNode *mergeTwoLists(ListNode *a, ListNode *b)
{
    ListNode *x = new ListNode();
    ListNode *y = x;

    while (a && b)
    {
        if (a->val <= b->val)
        {
            x->next = a;
            x = x->next;
            a = a->next;
        }
        else
        {
            x->next = b;
            x = x->next;
            b = b->next;
        }
    }

    if (a == NULL)
    {
        x->next = b;
    }
    if (b == NULL)
    {
        x->next = a;
    }

    return y->next;
}

int main()
{
    // Main function goes here
    return 0;
}