// Shibam Debnath
// May 26,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node
{
    int data;
    struct Node *next;
};


// multiply function

long long multiplyTwoLists(Node *first, Node *second)
{
    int n1 = 0, n2 = 0;
    if (first)
    {
        n1 = first->data;
    }
    first = first->next;
    while (first)
    {
        n1 = n1 * 10 + first->data;
        first = first->next;
    }

    if (second)
    {
        n2 = second->data;
    }
    second = second->next;
    while (second)
    {
        n2 = n2 * 10 + second->data;
        second = second->next;
    }

    return n1 * n2;
}



struct Node *newNode(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}



void push(struct Node **head_ref, int new_data)
{
    // allocate node
    struct Node *new_node = newNode(new_data);

    // link the old list off the new node
    new_node->next = (*head_ref);

    // move the head to point to the new node
    (*head_ref) = new_node;
}



void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        if (node->next)
            cout << "->";
        node = node->next;
    }
    cout << "\n";
}



int main()
{
    struct Node *first = NULL;
    struct Node *second = NULL;

    // create first list 9->4->6
    push(&first, 6);
    printf("First List is: ");
    printList(first);

    // create second list 8->4
    push(&second, 8);
    printf("Second List is: ");
    printList(second);

    // Multiply the two lists and see result
    cout << "Result is: ";
    cout << multiplyTwoLists(first, second);

    return 0;
}