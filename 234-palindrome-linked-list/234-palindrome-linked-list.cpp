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
    bool isPalindrome(ListNode* head) {
        ListNode *slow =head , *fast = head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast=fast->next->next;
        }
        
        // reverse 2nd half
        ListNode *rev = slow->next;
        slow->next = NULL;
        
        // reverse rev
        ListNode *prev = NULL , *temp = rev;
        while(rev){
            temp = rev->next;
            rev->next = prev;
            prev = rev;
            rev = temp;
        }
        
        // now our reversed wala is prev
        rev = prev;
        while(rev){
            if(rev->val != head->val) return false;
            rev = rev->next;
            head= head->next;
        }
        
        return true;
    }
};