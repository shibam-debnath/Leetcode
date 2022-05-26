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

ListNode *deleteDuplicates(ListNode *head)
{
    if (!head)
    {
        return head;
    }

    ListNode *temp = head;
    while (temp && temp->next)
    {
        if (temp->val == temp->next->val)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}
int main()
{
    // Main function goes here
    return 0;
}