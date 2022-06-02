//Shibam Debnath
//June 02,2022
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct ListNode{
    int val;
    ListNode *next;
};
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *start = new ListNode();
    start->next = head;
    
    // reach the node to be deleted using two pointer and delete that node 
    ListNode *slow = start, *fast = start;
    for (int i = 0; i < n; i++)
        fast = fast->next;

    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode *del = slow->next;
    slow->next = slow->next->next;
    delete (del);
    return start->next;
}
int main() {
    //Main function goes here
    return 0;
}