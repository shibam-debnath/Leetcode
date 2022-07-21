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
        ListNode *temp = head;
        for(int i=0;i<left-1;i++){
            temp=temp->next;
        }
        
        stack<int> st;
        int dist = right-left;
        ListNode *ptr = temp;
        for(int i=0;i<=dist;i++){
            st.push(ptr->val);
            ptr=ptr->next;
        }
        
        while(temp && !st.empty()){
            int v = st.top();
            st.pop();
            temp->val = v;
            temp=temp->next;
        }
        
        return head;
    }
};