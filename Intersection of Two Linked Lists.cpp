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
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    unordered_map<ListNode *, int> mp;

    while (headA)
    {
        mp[headA]++;
        headA = headA->next;
    }

    while (headB)
    {
        mp[headB]--;
        if (mp[headB] == 0)
        {
            return headB;
        }
        headB = headB->next;
    }
    return NULL;
}
int main()
{
    // Main function goes here
    return 0;
}