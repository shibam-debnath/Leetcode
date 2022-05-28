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

bool isPalindrome(ListNode *head)
{
    ListNode *temp = head;
    string s;
    while (temp)
    {
        s += to_string(temp->val);
        temp = temp->next;
    }
    string t = s;
    reverse(s.begin(), s.end());

    return s == t;
}

// 0(1) space
bool isPalindrome(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *rev;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    rev = slow;
    slow = slow->next;
    rev->next = NULL;

    ListNode *temp = head;
    while (slow)
    {
        temp = slow->next;
        slow->next = rev;
        rev = slow;
        slow = temp;
    }
    // now int the first half we have normal form but from middle half we have reverse form
    // 1->2->3<-2 < -1

    slow = head;
    fast = rev;

    while (fast)
    {
        if (fast->val != slow->val)
            return false;
        else
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return true;
}

int main()
{
    // Main function goes here
    return 0;
}