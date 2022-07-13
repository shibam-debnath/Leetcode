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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *temp = head;
        for(ListNode *i = head;i!= NULL;i=i->next){        
            for(ListNode *j = head;j!= NULL;j=j->next){
                if(j->val > i->val) swap(j->val,i->val);    
            }
        }      
        return head;
    }
};