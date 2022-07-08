/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_map<ListNode *,int> mp;

        while(head){
            mp[head]++;
            // already exists in map
            if(mp[head]==2){
                return head;
            }
            head = head->next;
        }
        return NULL;
    }
};