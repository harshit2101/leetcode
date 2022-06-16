/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp=head, *next, *runner;
        
        while(temp){
            if(temp->child){
                next=temp->next;
                temp->next=temp->child;
                temp->next->prev=temp;
                temp->child=NULL;
                
                runner = temp->next;
                while (runner->next) runner = runner->next;
                runner->next = next;
                if (runner->next) runner->next->prev = runner;
            }
            
            temp=temp->next;
        }
        
        return head;
    }
};