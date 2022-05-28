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
bool hasCycle(ListNode *head)
{
    ListNode *temp = head;
    ListNode *temp2 = head;

    unordered_map<int, int> mp;
    while (temp2 && temp2->next)
    {
        temp = temp->next;
        temp2 = temp2->next->next;
        if (temp == temp2)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    // Main function goes here
    return 0;
}