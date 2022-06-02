// Shibam Debnath
// May 26,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *sum = new ListNode();
    ListNode *temp = sum;

    int carry = 0, s = 0;
    while (l1 && l2)
    {
        s = l1->val + l2->val + carry;
        temp->next = new ListNode(s % 10);
        carry = s / 10;
        l1 = l1->next;
        l2 = l2->next;
        temp = temp->next;
    }
    while (l1)
    {
        s = l1->val + carry;
        temp->next = new ListNode(s % 10);
        carry = s / 10;
        l1 = l1->next;
        temp = temp->next;
    }
    while (l2)
    {
        s = l2->val + carry;
        temp->next = new ListNode(s % 10);
        carry = s / 10;
        l2 = l2->next;
        temp = temp->next;
    }

    if (carry)
    {
        temp->next = new ListNode(carry);
    }

    return sum->next;
}

int main()
{
    // Main function goes here
    return 0;
}