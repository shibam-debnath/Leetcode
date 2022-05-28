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

ListNode *middleNode(ListNode *head)
{
    ListNode *left = head;
    ListNode *right = head;

    while (right && right->next)
    {
        left = left->next;
        right = right->next->next;
    }

    return left;
}
int main()
{
    // Main function goes here
    return 0;
}