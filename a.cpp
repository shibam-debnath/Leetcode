// Shibam Debnath
// June ,2022

// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct listi
{
    int data;
    struct listi *next;
    listi() : data(0), next(nullptr){};
    listi(int x) : data(x), next(nullptr){};
    listi(int x, listi *next) : data(x), next(next) {}
};

typedef struct listi ELEMENT;

typedef ELEMENT *LINK;

LINK reverse(LINK head)
{
    // first remove duplicates
    struct listi *ptr1, *ptr2, *dup, *curr, *prev;
    ptr1 = head;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        while (ptr1->next)
        {
            prev = ptr1;
            curr = ptr1->next;
            ptr2 = ptr1->next;

            while (ptr2->next != NULL)
            {
                if (curr->data == ptr2->next->data)
                {
                    dup = curr;
                    prev->next = curr->next;
                    delete (curr);
                }
                else
                    ptr2 = ptr2->next;
            }
        }
        // now remove the 3--n occurances
        ptr2 = ptr1;
        // we are initializing flag =0 for each unique no
        // int flag = 0;
        /* Compare the picked element with rest
           of the elements */
        // while (ptr2->next != NULL)
        // {
        //     // for 1st and 2nd position
        //     if (flag == 0 && ptr1->data == ptr2->next->data)
        //     {
        //         // remove ptr1 , we want ptr2
        //         dup = ptr1;
        //         ptr1 = ptr1->next; // ptr1 removed
        //         delete (dup);
        //         flag = 1;    // first case handled
        //         ptr2 = ptr1; // start searching for other duplicates using ptr2 from here
        //     }
        //     else if (ptr1->data == ptr2->next->data)
        //     {
        //         // this time we need to remove ptr2
        //         dup = ptr2->next;
        //         ptr2->next = ptr2->next->next;
        //         delete (dup);
        //     }
        //     else
        //     {
        //         ptr2 = ptr2->next;
        //     }
        // }

        while (ptr2->next != NULL)
        {
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->next->data)
            {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    // now reverse the list

    listi *pre = NULL, *cur = head, *tmp;
    while (cur)
    {
        tmp = cur->next;
        cur->next = prev;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

void print(struct listi *node)
{
    while (node != NULL)
    {
        cout << node->data << "  ";
        node = node->next;
    }
}

int main()
{
    // Main function goes here

    struct listi *start = new listi(10);
    start->next = new listi(2);
    start->next->next = new listi(2);
    start->next->next->next = new listi(3);
    start->next->next->next->next = new listi(2);
    start->next->next->next->next->next = new listi(4);
    start->next->next->next->next->next->next = new listi(5);

    listi *ans = reverse(start);

    print(ans);

    // print_all(start);.
    return 0;
}