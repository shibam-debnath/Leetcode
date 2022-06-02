// Shibam Debnath
// June 02,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// *using unordered map

Node *copyRandomList(Node *head)
{
    Node *copy = head;

    // we are using map to optimize the searching to O(1)
    unordered_map<Node *, Node *> mp;

    while (copy)
    {
        mp[copy] = new Node(copy->val);
        copy = copy->next;
    }

    // we have already linked cloned and original list
    // now update the next and random pointer of cloned listusing the mp;

    Node *temp = head;
    while (temp)
    {
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }

    // return the head node of the map
    return mp[head];
}

int main()
{
    // Main function goes here
    return 0;
}