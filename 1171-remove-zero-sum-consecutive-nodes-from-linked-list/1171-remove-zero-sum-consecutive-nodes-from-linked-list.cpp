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
        ListNode* removeZeroSumSublists(ListNode *root)
        {
            int sum =0;
            unordered_map<int,ListNode*> mp;
            
            ListNode *head = new ListNode(0);
            ListNode *temp = new ListNode(0);
            head->next = root;
            temp->next = root;
            
            // mp[0] = NULL;
            
            while (head)
            {
                sum+=head->val;
                mp[sum] = head;
                head = head->next;
            }
            
            sum =0;
            for(ListNode *t = temp ; t != NULL;t = t->next){
                sum+=t->val;
                if(mp.count(sum)){
                    t->next = mp[sum]->next;
                }
            }
            
            return temp->next;
        }
};