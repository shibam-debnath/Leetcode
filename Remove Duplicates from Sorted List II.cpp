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
    // to handle the beg edge case we are adding a node with val 0 to the beg
    // of head node and in the return we are just returnng ans->next
    ListNode *ans = new ListNode();
    ans->val = 0;
    ans->next = head;
    ListNode *temp = ans;

    // normal iterative loop
    while (head && head->next)
    {
        if (head->val == head->next->val)
        {
            while (head->next && head->val == head->next->val)
            {
                head = head->next;
                temp->next = head->next;
            }
        }
        else
        {
            temp = temp->next;
        }

        head = head->next;
    }
    return ans->next;
}
int main()
{
    // Main function goes here
    return 0;
}