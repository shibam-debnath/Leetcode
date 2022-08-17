/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// Time complexity - O(n)
// Space complexity - O(n) , we can further optimize space complexity by not using the map

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp = head;
        
        //create unordered map to store the cloned Node as value and key = original Node 
        unordered_map<Node*,Node*> mp;
        
        // create & insert elements to unordered map
        while(temp!= NULL){
            
            // create a node with same value as original node and insert that (as value) to mp[temp]
            mp[temp] = new Node(temp->val);
            temp=temp->next;
        }
        
        // now as we have inserted all the nodes to map , start joining the links 
        temp=head;
        while(temp){
            
            // cloned node(mp[temp]) ka next == original node(temp) jaha point karna hein waha waha
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            
            temp=temp->next;
        }
        
        //finally return the cloned node ka starting point which is mp[head]
        return mp[head];
    }
};