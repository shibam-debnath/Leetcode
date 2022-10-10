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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        // n==1
        if(!head->next){
            return NULL;
        } 
        
        
        auto *slow =head;
        auto *fast =head->next->next;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow=slow->next;
        }

        slow->next = slow->next->next;
        
        return head;
    }
};