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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode *temp = head,*sec=NULL,*fir=NULL;
        for(int i=0;i<left-1;i++){
            fir=temp;
            temp=temp->next;
        }
        
        sec=temp;
        // cout << fir->val << " " << sec->val << endl;
        int dist = right-left;
        ListNode *prev = temp , *curr=temp->next;
        
        while(curr && dist--){
            temp=curr->next;
            curr->next = prev;
            prev=curr;
            curr=temp;
        }
        
        // main connection
        sec->next = curr;
        
        if(left==1) return prev;
        
        fir->next = prev;
        
        return head;
    }
};