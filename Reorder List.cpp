// Shibam Debnath
// June 02,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct ListNode
{
    int val;
    ListNode *next;
};

void reorderList(ListNode *head)
{
    ListNode *temp = head;

    stack<ListNode *> st;
    int c = 0;
    while (temp)
    {
        st.push(temp);
        temp = temp->next;
        c++;
    }
    temp = head;
    for (int i = 0; i < c / 2; i++)
    {
        ListNode *node = st.top();
        st.pop();
        node->next = temp->next;
        temp->next = node;
        temp = temp->next->next;
    }
    temp->next = NULL; // used to trim the linked list at the middle since we are additionally inserting nodes
}

int main()
{
    // Main function goes here
    return 0;
}