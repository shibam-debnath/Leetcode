//Shibam Debnath
//May 26,2022
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct ListNode
{
    int val;
    ListNode *next;
};


void *sort_linked(ListNode *head){
    vector<int> v(3, 0);
    ListNode *ptr = head;
    while(ptr){
        v[ptr->val] += 1;
        ptr = ptr->next;
    }
    int i = 0;
    ptr = head;   // again using same ptr 
    while (ptr)
    {
        if(v[i] != 0){ //untill no of 0,1,2 is empty keep inserting i
            ptr->val = i;
            ptr = ptr->next;
            v[i]--;
        }
        else{
            i++;
        }
    }
    
}
int main() {
    //Main function goes here
    return 0;
}