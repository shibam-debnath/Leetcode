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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *second =head, *ptr2 = head;
        
        for(int i=1;i<k;i++){
            ptr2 = ptr2->next;
        }
        
        ListNode *first = ptr2;
        
        while(ptr2->next){
            ptr2=ptr2->next;
            second=second->next;
        }
        
        swap(first->val,second->val);
        
        return head;
    }
};