/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        // very important
        if(!head || !head->next) return head;
        
        // take two pointers to divide the linked list into two equal parts
        ListNode *slow = head, *fast = head;
        ListNode *middle = NULL;

        while (fast && fast->next)
        {
            middle = slow; // since slow ek step aage chala jaata h uuse pehle wala is mid
            slow = slow->next; // slow is the head of 2nd half
            fast = fast->next->next;
        }
        
        middle->next = NULL; // end of first half 

        // divide
        
        ListNode *left = sortList(head);
        
        ListNode *right = sortList(slow);

        // merge
        return merge(left, right);
    }

    ListNode *merge(ListNode *l, ListNode *r)
    {
        // create new ListNode and store ans there (initalized with zero)
        ListNode *node = new ListNode(0);

        // take a pointer to traverse and add
        ListNode *ptr = node;

        while (l && r)
        {
            if (l->val <= r->val)
            {
                ptr->next = new ListNode(l->val);
                l = l->next;
            }
            else
            {
                ptr->next = new ListNode(r->val);
                r = r->next;
            }
            ptr = ptr->next;
        }

        // if only l exist just add it to the ptr
        if (l)
        {
            ptr->next = l;
        }

        // if only nright exists
        if (r)
        {
            ptr->next = r;
        }

        return node->next;
    }
};