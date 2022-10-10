// Using HashMap

// class Solution
// {
//     public:
//         ListNode* detectCycle(ListNode *head)
//         {

//             unordered_map<ListNode*, int> mp;

//             while (head)
//             {
//                 mp[head]++;
//                	// already exists in map
//                 if (mp[head] == 2)
//                 {
//                     return head;
//                 }
//                 head = head->next;
//             }
//             return NULL;
//         }
// };

// Using Two Pointer

class Solution
{
    public:
        ListNode* detectCycle(ListNode *head)
        {

            ListNode *slow = head, *fast = head;

            while (fast && fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
                
                if (slow == fast)
                {
                    slow = head;
                    while (slow!=fast)
                    {
                        slow=slow->next;
                        fast=fast->next;
                    }
                    return slow;
                }
            }

            return NULL;
        }
};