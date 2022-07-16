// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        // Base condition.
        if (head == NULL)
        {
            return head;
        }

        int len = 1;
        ListNode *temp = head;

        // Calculate length of the linked list.
        while (temp->next != NULL)
        {
            temp = temp->next;
            len += 1;
        }

        k = k % len;

        // Number of rotations are same as len so no change in LL.
        if (k == len || k == 0)
        {
            return head;
        }

        // To make a circular linked list.
        temp->next = head;

        temp = head;

        for (int i = 0; i < abs(len - k - 1); i++)
        {
            temp = temp->next;
        }

        // since temp is last node it's next node will be first one
        head = temp->next;
        // temp is the last node
        temp->next = NULL;

        return head;
    }
};

int main()
{
    // Main function goes here
    return 0;
}