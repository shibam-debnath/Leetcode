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
ListNode *removeElements(ListNode *head, int val)
{
    ListNode *ptr = head;

    while (ptr && ptr->next)
    {
        if (ptr->next->val == val)
        {
            ptr->next = ptr->next->next;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    ptr = head;

    if (ptr && ptr->val == val)
    {
        head = ptr->next;
    }
    return head;
}
int main()
{
    // Main function goes here
    return 0;
}