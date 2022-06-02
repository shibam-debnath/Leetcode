// Shibam Debnath
// May 26,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node
{
public:
    int data;
    Node *next;
};

void push(Node **head_ref, int new_data)
{

    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void deleteNode(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    if (node->next)
    {
        Node *temp = node->next;
        node->data = temp->data;
        node->next = temp->next;
        free(temp);
    }
    else if (node->next == NULL)
    {
        node = NULL;
        return;
    }
}
int main()
{

    Node *head = NULL;

    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);

    cout << "Before deleting \n";
    printList(head);

    deleteNode(head->next->next);

    cout << "\nAfter deleting \n";
    printList(head);
    return 0;
}
