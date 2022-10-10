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

        head = temp->next;
        temp->next = NULL;

        return head;
    }
};