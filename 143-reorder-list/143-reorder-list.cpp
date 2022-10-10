/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        void reorderList(ListNode *head)
        {
            if(!head->next) return;
            
            ListNode *temp = head, * slow = head, *fast = head , *prev=head ;
            
            while(fast && fast -> next){
                prev = slow;
                slow = slow -> next,
                fast = fast -> next -> next;            // fast moves at 2x speed     
            }
            
            
            ListNode *ans = new ListNode(0);
            ListNode *headd = ans;
            
            prev->next = NULL;
            prev = head; // first half
            ListNode *rev = reverse(slow); // second half
            
            while(prev or rev){
                if(prev){
                    headd->next = prev;
                    headd=headd->next;
                    prev=prev->next;
                }
                if(rev){
                    headd->next = rev;
                    headd=headd->next;
                    rev=rev->next;
                }
            }
            head = ans->next;
        }
    
    ListNode * reverse(ListNode *head){
        ListNode *prev = NULL;
        while(head) {
            ListNode* nextNode = head -> next;  
            head -> next = prev; 
            prev = head;                   
            head = nextNode;         
        }
        return prev;
    }
};