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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first = head, *second = head , *prev = head;
        
        int k=n;
        int len = n;
        while(n--){
            first=first->next;
        }
        
        while(first){
            k++;
            prev = second;
            second = second->next;
            first=first->next;
        }
        // if n is len then return head next
    
        if(k==len){
            return head->next;  
        } 

        if(second->next){
            prev->next = second->next;
        }
        else{
            prev->next = NULL;
        }
        
        return head;
    }
};