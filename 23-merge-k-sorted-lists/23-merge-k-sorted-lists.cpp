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

// Constant space approach
class Solution
{
    public:
    ListNode* mergeKLists(vector<ListNode*> &lists)
    {
        int n = lists.size();
        if (lists.empty()) return NULL;
        for (int i = 1; i < n; i++)
        {
            lists[0] = mergeTwoLists(lists[0], lists[i]);
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};