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
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    ListNode *temp = head;
    for (int i = 0; i < left - 1; i++)
    {
        temp = temp->next;
    }

    ListNode *ptr = temp;
    stack<int> st;
    for (int i = 0; i <= right - left; i++)
    {
        st.push(ptr->val);
        ptr = ptr->next;
    }

    while (temp && !st.empty())
    {
        temp->val = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

int main()
{
    // Main function goes here
    return 0;
}