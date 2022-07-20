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
        
        while(fast && fast->next){
            slow = slow->next;
            fast=fast->next->next;
        }
        
        // reverse 2nd half
        
        ListNode *rev=slow;
        slow=slow->next;
        
        // this cuts the second half end to NULL
        rev->next=NULL;
        
        // reverse 2nd half
        ListNode *temp = slow;
        while(slow){
            temp=slow->next;
            slow->next = rev;
            rev=slow;
            slow=temp;
        }

        slow = head;
        
        while(rev){
            cout << rev->val << " " << slow->val << endl;
            if(rev->val != slow->val) return false;
            rev=rev->next;
            slow=slow->next;
        }
        
        return true;
    }
};