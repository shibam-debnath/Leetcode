/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* oddEvenList(ListNode *head)
        {
            ListNode *odd = new ListNode(0);
            ListNode *even = new ListNode(0);
            
            ListNode *oddd=odd,*evenn=even;
            
            int c=1;
            
            while (head)
            {
                if (c&1)
                { 
                    oddd->next = new ListNode(head->val);
                    oddd=oddd->next;
                    // cout << odd->val << " ";
                }
                else{
                    
                    evenn->next = new ListNode(head->val);
                    evenn=evenn->next;
                } 
                c++;
                head = head->next;
            }
            
            ListNode *temp = odd;
            
            while(temp->next){
                // cout << temp->val <<  " ";
                temp = temp->next;
            }
            
            temp->next = even->next;

            return odd->next;
        }
};