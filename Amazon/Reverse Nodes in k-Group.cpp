// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct ListNode
{
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        ListNode *next = NULL;
    }
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Using stack
// Time Complexity - O(n*k)
// Space Complexity - O(k)
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *fast = head, *slow = head;
        stack<int> st;
        while (fast)
        {
            for (int i = 0; i < k; i++)
            {
                if (fast)
                    st.push(fast->val);
                else
                    return head;
                fast = fast->next;
            }
            while (!st.empty())
            {
                slow->val = st.top();
                st.pop();
                slow = slow->next;
            }
        }
        return head;
    }
};

int main()
{
    // Main function goes here
    return 0;
}