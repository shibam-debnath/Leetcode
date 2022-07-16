// Shibam Debnath
// June ,2022

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
    ListNode *sortList(ListNode *head)
    {
        // divide into two halfs
        ListNode *slow = head, *fast = head;

        while (fast)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = NULL;

        // divide
        ListNode *left = sortList(slow);
        ListNode *right = sortList(fast);

        // merge
        ListNode *ans = merge(left, right);
        return ans;
    }

    ListNode *merge(ListNode *l, ListNode *r)
    {

        // create new ListNode and store ans there (initalized with zero)
        ListNode *node = new ListNode(0);

        // take a pointer to traverse and add
        ListNode *ptr = node;

        while (l && r)
        {
            if (l->val < r->val)
            {
                ptr->next = l;
                l = l->next;
            }
            else
            {
                ptr->next = r;
                r = r->next;
            }
            ptr = ptr->next;
        }

        // if only l exist just add it to the ptr
        if (l)
        {
            ptr->next = l;
            // l = l->next;
        }

        // if only nright exists
        if (r)
        {
            ptr->next = r;
        }

        return node->next;
    }
};

int main()
{
    // Main function goes here
    return 0;
}