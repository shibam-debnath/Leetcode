/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode() : val(0), next(nullptr) {}
 *  ListNode(int x) : val(x), next(nullptr) {}
 *  ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:

        ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
        {
            if (!l1) return l2;
            if (!l2) return l1;

           	// if l1 is not smaller swap
            if (l1->val > l2->val)
            {
                ListNode *temp = l1;
                l1 = l2;
                l2 = temp;
            }

            ListNode *res = l1;
            while (l1 && l2)
            {
               	// keep going untill sorted is breaked
                ListNode *prev = NULL;

                while (l1 and l1->val <= l2->val)
                {
                   	// store prev wala in temp so that we can break and connect to l2 
                    prev = l1;
                    l1 = l1->next;
                }

               	// here l1>l2 so berak and add to l2
                prev->next = l2;

               	// again swap since chota wala ab opposite wale mein mil gaya
                ListNode *temp = l1;
                l1 = l2;
                l2 = temp;
            }
            return res;
        }
};