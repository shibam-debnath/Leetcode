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

// One way
ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *ptr = head;
    head = head->next;
    ptr->next = NULL;
    ListNode *temp;
    while (head)
    {
        temp = head->next;
        head->next = ptr;
        ptr = head;
        head = temp;
    }

    return ptr;
}

// 2nd iterative way
ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    ListNode *ptr = NULL, *temp;
    while (head)
    {
        temp = head->next;
        head->next = ptr;
        ptr = head;
        head = temp;
    }

    return ptr;
}
// Recusrsive way

ListNode *helper(ListNode *head, ListNode *prev)
{
    // base case
    if (!head)
    {
        return prev;
    }
    // recursion logic
    ListNode *next = head->next;
    head->next = prev;
    return helper(next, head);
}

ListNode *reverseList(ListNode *head)
{
    return helper(head, NULL);
}

int main()
{
    // Main function goes here
    return 0;
}