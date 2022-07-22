/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* partition(ListNode *head, int x)
        {
            ListNode *odd = new ListNode(0);
            ListNode *even = new ListNode(0);

            ListNode *oddd = odd, *evenn = even;

            while (head)
            {
                if (head->val<x)
                {
                    oddd->next = new ListNode(head->val);
                    oddd = oddd->next;
                }
                else
                {
                    evenn->next = new ListNode(head->val);
                    evenn = evenn->next;
                }
                
                head = head->next;
            }
            evenn->next = NULL;
            oddd->next = even->next;
            return odd->next;
        }
};