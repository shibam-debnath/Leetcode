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
    stack<int> stackA;
    stack<int> stackB;

    while (l1)
    {
        stackA.push(l1->val);
        l1 = l1->next;
    }

    while (l2)
    {
        stackB.push(l2->val);
        l2 = l2->next;
    }

    ListNode *Temp = new ListNode(0);
    Temp->next = nullptr;
    int carry = 0, num1 = 0, num2 = 0;

    while (!stackA.empty() || !stackB.empty() || carry)
    {

        if (!stackA.empty())
        {
            num1 = stackA.top();
            stackA.pop();
        }

        if (!stackB.empty())
        {
            num2 = stackB.top();
            stackB.pop();
        }

        int sum = num1 + num2 + carry;
        int value = sum % 10;
        carry = sum / 10;

        num1 = 0;
        num2 = 0;

        ListNode *newNode = new ListNode(value);
        newNode->next = Temp->next;
        Temp->next = newNode;
    }
    return Temp->next;
}

int main()
{
    // Main function goes here
    return 0;
}