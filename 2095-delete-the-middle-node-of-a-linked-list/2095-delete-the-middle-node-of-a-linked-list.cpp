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
        
        if(!head->next->next){
            head->next = NULL;
            return head;
        } 
   
        ListNode *slow =head , *fast =head , *temp = head;
        
        while(fast && fast->next){
            slow=slow->next;
            fast = fast->next->next;
        }
        
        while(temp->next!= slow){
            temp = temp->next;
        }
        
        temp->next = slow->next;

        // slow->next = slow->next->next;
        
        return head;
    }
};