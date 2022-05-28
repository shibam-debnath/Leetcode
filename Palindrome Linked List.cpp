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
int main()
{
    // Main function goes here
    return 0;
}