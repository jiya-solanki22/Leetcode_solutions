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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node* curr = head;
        while(curr) 
        {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }
        curr = head;
        while(curr) 
        {
            if(curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        curr = head;
        Node* newHead = head->next;
        Node* newCurr = newHead;
        while (curr) {
            curr->next = newCurr->next;
            curr = curr->next;
            if (curr) {
                newCurr->next = curr->next;
                newCurr = newCurr->next;
            }
        }
        return newHead;
    }
};